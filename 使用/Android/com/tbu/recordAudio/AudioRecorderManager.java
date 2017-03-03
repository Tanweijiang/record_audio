package com.tbu.recordAudio;

/**
 * �����ϴ�
 * @author Rex.lsf
 * ����������ϵQQ:271809781
 * 
 * add by tanweijiang
 * qq: 704177907
 */
import java.io.File;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

import android.app.Activity;
import android.app.Dialog;
import android.graphics.Color;
import android.media.MediaPlayer;
import android.media.MediaPlayer.OnCompletionListener;
import android.os.Environment;
import android.os.Handler;
import android.os.Message;
import android.view.Gravity;
import android.view.View;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

public class AudioRecorderManager {

	/*
	 * ¼���ײ���
	 */
	private AudioRecorder mr; // ¼���ײ�
	private MediaPlayer mediaPlayer; // ����������

	private static Activity appActivity;

	private Dialog dialog;

	private TextView luyin_txt, luyin_path, record_memo, player_memo;
	private Thread recordThread; // ¼����ʱ�߳�

	private static int MAX_TIME = 0; // �¼��ʱ�䣬��λ�룬0Ϊ��ʱ������
	private static int MIX_TIME = 1; // ���¼��ʱ�䣬��λ�룬0Ϊ��ʱ�����ƣ�������Ϊ1
	private static int RECODE_STATE = 0; // ¼����״̬
	private static int RECORD_NO = 0; // ����¼��
	private static int RECORD_ING = 1; // ����¼��
	private static int RECODE_ED = 2; // ���¼��
	public static float recodeTime = 0.0f; // ¼����ʱ��
	private static double voiceValue = 0.0; // ��˷��ȡ������ֵ

	private static boolean playState = false; // ����״̬
	private String date = "";

	public void init(Activity activity) {
		appActivity = activity;
		luyin_txt = new TextView(appActivity); // ¼��ʵ��ʱ�� �ı�
		luyin_path = new TextView(appActivity); // �ļ����·��
		record_memo = new TextView(appActivity); // ��ʾ���� "��ס����¼��"
		player_memo = new TextView(appActivity); // ��ʾ���� "����¼��"
	}

	// ��ʼ¼�� ¼����ť���µ��� btnDown
	public void beginRecordAudio() {
		if (RECODE_STATE != RECORD_ING) {
			// scanOldFile();
			date = new SimpleDateFormat("yy-MM-dd-HH-mm-ss",
					Locale.getDefault()).format(new Date());
			mr = new AudioRecorder(date);
			RECODE_STATE = RECORD_ING;
			showVoiceDialog();
			try {
				mr.start();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			mythread();
		}
	}

	// ¼������ ¼����ť������� btnUp
	public void endRecordAudio() {
		if (RECODE_STATE == RECORD_ING) {
			RECODE_STATE = RECODE_ED;
			try {
				mr.stop();
				voiceValue = 0.0;
			} catch (IOException e) {
				e.printStackTrace();
			}

			if (recodeTime < MIX_TIME) {
				showWarnToast();
				record_memo.setText("��ס��ʼ¼��");
				RECODE_STATE = RECORD_NO;
				File file = new File(Environment.getExternalStorageDirectory(),
						"my/" + date + ".amr");
				file.delete();
			} else {
				// record.setText("¼�����!�������¼��");
				record_memo.setText("¼�����!�������¼��");
				player_memo.setVisibility(View.VISIBLE);
				luyin_txt.setText("¼��ʱ�䣺" + ((int) recodeTime));
				luyin_path.setText("�ļ�·����" + getAmrPath());
				// try {
				// SyncHttp.uploadFile("http://192.168.1.125:8887/upload.php",
				// getAmrPath());
				// } catch (IOException e) {
				// Toast.makeText(RecordActivity.this, "�ϴ�ʧ��",
				// Toast.LENGTH_LONG).show();
				// e.printStackTrace();
				// }
			}
		}
	}

	// ����¼��
	public void playAudio() {

		if (!playState) {
			mediaPlayer = new MediaPlayer();
			try {
				mediaPlayer.setDataSource(getAmrPath());
				mediaPlayer.prepare();
				mediaPlayer.start();
				player_memo.setText("���ڲ���");
				playState = true;
				// ���ò��Ž���ʱ����
				mediaPlayer.setOnCompletionListener(new OnCompletionListener() {

					@Override
					public void onCompletion(MediaPlayer mp) {
						if (playState) {
							player_memo.setText("������沥������");
							playState = false;
						}
					}
				});
			} catch (IllegalArgumentException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IllegalStateException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		} else {
			if (mediaPlayer.isPlaying()) {
				mediaPlayer.stop();
				playState = false;
			} else {
				playState = false;
			}
			player_memo.setText("������沥��¼��");
		}
	}

	// ɾ���ļ� ¼��
	public void deleteFile() {
		File file = new File(Environment.getExternalStorageDirectory() + "/my");
		File f[] = file.listFiles();
		for (int i = 0; i < f.length; i++) {
			f[i].delete();
		}
		File g[] = file.listFiles();
		if (g.length == 0) {
			player_memo.setVisibility(View.GONE);
			Toast.makeText(appActivity, "ɾ���ɹ�", Toast.LENGTH_LONG).show();
		}

	}

	// ¼��ʱ��ʾDialog
	public void showVoiceDialog() {

	}

	// ¼��ʱ��̫��ʱToast��ʾ
	public void showWarnToast() {
		Toast toast = new Toast(appActivity);
		LinearLayout linearLayout = new LinearLayout(appActivity);
		linearLayout.setOrientation(LinearLayout.VERTICAL);
		linearLayout.setPadding(20, 20, 20, 20);

		// ����һ��ImageView
		ImageView imageView = new ImageView(appActivity);
		//imageView.setImageResource(R.drawable.voice_to_short); // ͼ��

		TextView mTv = new TextView(appActivity);
		mTv.setText("ʱ��̫��   ¼��ʧ��");
		mTv.setTextSize(14);
		mTv.setTextColor(Color.WHITE);// ������ɫ
		// mTv.setPadding(0, 10, 0, 0);

		// ��ImageView��ToastView�ϲ���Layout��
		linearLayout.addView(imageView);
		linearLayout.addView(mTv);
		linearLayout.setGravity(Gravity.CENTER);// ���ݾ���
		//linearLayout.setBackgroundResource(R.drawable.record_bg);// �����Զ���toast�ı���

		toast.setView(linearLayout);
		toast.setGravity(Gravity.CENTER, 0, 0);// ���λ��Ϊ�м� 100Ϊ������100dp
		toast.show();
	}

	// ��ȡ�ļ��ֻ�·��
	public String getAmrPath() {
		File file = new File(Environment.getExternalStorageDirectory(), "my/"
				+ date + ".amr");
		return file.getAbsolutePath();
	}

	// ¼����ʱ�߳�
	public void mythread() {
		recordThread = new Thread(ImgThread);
		recordThread.start();
	}

	// ¼��DialogͼƬ��������С�л�
	public void setDialogImage() {

	}

	// ¼���߳�
	public Runnable ImgThread = new Runnable() {

		@Override
		public void run() {
			recodeTime = 0.0f;
			while (RECODE_STATE == RECORD_ING) {
				if (recodeTime >= MAX_TIME && MAX_TIME != 0) {
					imgHandle.sendEmptyMessage(0);
				} else {
					try {
						Thread.sleep(200);
						recodeTime += 0.2;
						if (RECODE_STATE == RECORD_ING) {
							voiceValue = mr.getAmplitude();
							imgHandle.sendEmptyMessage(1);
						}
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			}
		}

		Handler imgHandle = new Handler() {
			@Override
			public void handleMessage(Message msg) {

				switch (msg.what) {
				case 0:
					// ¼������15���Զ�ֹͣ
					if (RECODE_STATE == RECORD_ING) {
						RECODE_STATE = RECODE_ED;
					
						try {
							mr.stop();
							voiceValue = 0.0;
						} catch (IOException e) {
							e.printStackTrace();
						}

						if (recodeTime < 1.0) {
							showWarnToast();
							record_memo.setText("��ס��ʼ¼��");
							RECODE_STATE = RECORD_NO;
						} else {
							record_memo.setText("¼�����!�������¼��");
							luyin_txt.setText("¼��ʱ�䣺" + ((int) recodeTime));
							luyin_path.setText("�ļ�·����" + getAmrPath());
						}
					}
					break;
				case 1:
					//setDialogImage();
					break;
				default:
					break;
				}
			}
		};
	};

}
