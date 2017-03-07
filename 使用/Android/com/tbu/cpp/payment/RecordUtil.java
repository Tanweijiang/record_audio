package org.cocos2dx.cpp.payment;

import android.app.Activity;
import android.util.Log;

import com.tbu.recordAudio.AudioRecorderManager;

public class RecordUtil {

	private static Activity activity;
	private static final String POXIAOSIGN = "poxiaosign_tniuniu";
	private static AudioRecorderManager audioManager;
	
	public static void init(Activity activity) {
		RecordUtil.activity = activity;
		audioManager = new AudioRecorderManager();
		audioManager.init(RecordUtil.activity);	
	}
	
	
	/**
	 * 开始录音
	 */
	public static void beginRecordAudio() {
	Log.w("recordAudio","==RecordUtil::beginRecordAudio==");
		audioManager.beginRecordAudio();	
	}
	
	/**
	 * 结束录音
	 */
	public static void endRecordAudio() {
		Log.w("recordAudio","==RecordUtil::endRecordAudio==");
		audioManager.endRecordAudio();
	}
	
	/**
	 * 播放录音
	 */
	public static void playAudio() {
		Log.w("recordAudio","==RecordUtil::playAudio==");
		audioManager.playAudio();
	}
	
	/**
	 *  删除录音
	 */
	public static void deleteFile() {
		Log.w("recordAudio","==RecordUtil::deleteFile==");
		audioManager.deleteFile();
	}
	
	/**
	 * 获取录音路径
	 */
	public static void getRecordFilePath() {
		Log.w("recordAudio","==RecordUtil::getRecordFilePath==");   
		audioManager.getAmrPath();
		// todo
	}
	
	
}
