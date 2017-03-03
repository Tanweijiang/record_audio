package com.tbu.recordAudio;

import java.io.File;
import java.io.IOException;

import android.media.AudioFormat;
import android.media.MediaRecorder;
import android.os.Environment;

public class AudioRecorder
{
	private static int SAMPLE_RATE_IN_HZ = 8000; 

	final MediaRecorder recorder = new MediaRecorder();
	final String path;

	public AudioRecorder(String path)
	{
		this.path = sanitizePath(path);
	}

	private String sanitizePath(String path)
	{
		if (!path.startsWith("/"))
		{
			path = "/" + path;
		}
		if (!path.contains("."))
		{
			path += ".amr";
		}
		return Environment.getExternalStorageDirectory().getAbsolutePath()
				+ "/my" + path;
	}

	// ¿ªÊ¼Â¼Òô
	public void start() throws IOException
	{
		String state = android.os.Environment.getExternalStorageState();
		if (!state.equals(android.os.Environment.MEDIA_MOUNTED)) { throw new IOException(
				"SD Card is not mounted,It is  " + state + "."); }
		File directory = new File(path).getParentFile();
		if (!directory.exists() && !directory.mkdirs()) { throw new IOException(
				"Path to file could not be created"); }
		recorder.setAudioSource(MediaRecorder.AudioSource.MIC);
		recorder.setOutputFormat(MediaRecorder.OutputFormat.RAW_AMR);
		recorder.setAudioEncoder(MediaRecorder.AudioEncoder.AMR_NB);
		recorder.setAudioSamplingRate(SAMPLE_RATE_IN_HZ);
		recorder.setOutputFile(path);
		recorder.prepare();
		recorder.start();
	}

	// Í£Ö¹Â¼Òô
	public void stop() throws IOException
	{
		recorder.stop();
		recorder.release();
	}
	
	// µÃµ½  Õñ·ù
	public double getAmplitude() {		
		if (recorder != null){			
			return  (recorder.getMaxAmplitude());		
			}		
		else			
			return 0;	
		}
}