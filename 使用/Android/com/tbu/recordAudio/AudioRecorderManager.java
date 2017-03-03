package com.tbu.recordAudio;

/**
 * 语音上传
 * @author Rex.lsf
 * 有问题请联系QQ:271809781
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
	 * 录音底层类
	 */
	private AudioRecorder mr; // 录音底层
	private MediaPlayer mediaPlayer; // 声音播放类

	private static Activity appActivity;

	private Dialog dialog;

	private TextView luyin_txt, luyin_path, record_memo, player_memo;
	private Thread recordThread; // 录音计时线程

	private static int MAX_TIME = 0; // 最长录制时间，单位秒，0为无时间限制
	private static int MIX_TIME = 1; // 最短录制时间，单位秒，0为无时间限制，建议设为1
	private static int RECODE_STATE = 0; // 录音的状态
	private static int RECORD_NO = 0; // 不在录音
	private static int RECORD_ING = 1; // 正在录音
	private static int RECODE_ED = 2; // 完成录音
	public static float recodeTime = 0.0f; // 录音的时间
	private static double voiceValue = 0.0; // 麦克风获取的音量值

	private static boolean playState = false; // 播放状态
	private String date = "";

	public void init(Activity activity) {
		appActivity = activity;
		luyin_txt = new TextView(appActivity); // 录音实现时间 文本
		luyin_path = new TextView(appActivity); // 文件存放路劲
		record_memo = new TextView(appActivity); // 提示文字 "按住进行录音"
		player_memo = new TextView(appActivity); // 提示文字 "播放录音"
	}

	// 开始录音 录音按钮按下调用 btnDown
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

	// 录音结束 录音按钮弹起调用 btnUp
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
				record_memo.setText("按住开始录音");
				RECODE_STATE = RECORD_NO;
				File file = new File(Environment.getExternalStorageDirectory(),
						"my/" + date + ".amr");
				file.delete();
			} else {
				// record.setText("录音完成!点击重新录音");
				record_memo.setText("录音完成!点击重新录音");
				player_memo.setVisibility(View.VISIBLE);
				luyin_txt.setText("录音时间：" + ((int) recodeTime));
				luyin_path.setText("文件路径：" + getAmrPath());
				// try {
				// SyncHttp.uploadFile("http://192.168.1.125:8887/upload.php",
				// getAmrPath());
				// } catch (IOException e) {
				// Toast.makeText(RecordActivity.this, "上传失败",
				// Toast.LENGTH_LONG).show();
				// e.printStackTrace();
				// }
			}
		}
	}

	// 播放录音
	public void playAudio() {

		if (!playState) {
			mediaPlayer = new MediaPlayer();
			try {
				mediaPlayer.setDataSource(getAmrPath());
				mediaPlayer.prepare();
				mediaPlayer.start();
				player_memo.setText("正在播放");
				playState = true;
				// 设置播放结束时监听
				mediaPlayer.setOnCompletionListener(new OnCompletionListener() {

					@Override
					public void onCompletion(MediaPlayer mp) {
						if (playState) {
							player_memo.setText("点击上面播放声音");
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
			player_memo.setText("点击上面播放录音");
		}
	}

	// 删除文件 录音
	public void deleteFile() {
		File file = new File(Environment.getExternalStorageDirectory() + "/my");
		File f[] = file.listFiles();
		for (int i = 0; i < f.length; i++) {
			f[i].delete();
		}
		File g[] = file.listFiles();
		if (g.length == 0) {
			player_memo.setVisibility(View.GONE);
			Toast.makeText(appActivity, "删除成功", Toast.LENGTH_LONG).show();
		}

	}

	// 录音时显示Dialog
	public void showVoiceDialog() {

	}

	// 录音时间太短时Toast显示
	public void showWarnToast() {
		Toast toast = new Toast(appActivity);
		LinearLayout linearLayout = new LinearLayout(appActivity);
		linearLayout.setOrientation(LinearLayout.VERTICAL);
		linearLayout.setPadding(20, 20, 20, 20);

		// 定义一个ImageView
		ImageView imageView = new ImageView(appActivity);
		//imageView.setImageResource(R.drawable.voice_to_short); // 图标

		TextView mTv = new TextView(appActivity);
		mTv.setText("时间太短   录音失败");
		mTv.setTextSize(14);
		mTv.setTextColor(Color.WHITE);// 字体颜色
		// mTv.setPadding(0, 10, 0, 0);

		// 将ImageView和ToastView合并到Layout中
		linearLayout.addView(imageView);
		linearLayout.addView(mTv);
		linearLayout.setGravity(Gravity.CENTER);// 内容居中
		//linearLayout.setBackgroundResource(R.drawable.record_bg);// 设置自定义toast的背景

		toast.setView(linearLayout);
		toast.setGravity(Gravity.CENTER, 0, 0);// 起点位置为中间 100为向下移100dp
		toast.show();
	}

	// 获取文件手机路径
	public String getAmrPath() {
		File file = new File(Environment.getExternalStorageDirectory(), "my/"
				+ date + ".amr");
		return file.getAbsolutePath();
	}

	// 录音计时线程
	public void mythread() {
		recordThread = new Thread(ImgThread);
		recordThread.start();
	}

	// 录音Dialog图片随声音大小切换
	public void setDialogImage() {

	}

	// 录音线程
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
					// 录音超过15秒自动停止
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
							record_memo.setText("按住开始录音");
							RECODE_STATE = RECORD_NO;
						} else {
							record_memo.setText("录音完成!点击重新录音");
							luyin_txt.setText("录音时间：" + ((int) recodeTime));
							luyin_path.setText("文件路径：" + getAmrPath());
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
