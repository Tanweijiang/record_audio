# record_audio

give qiu le ge zhong 

ond day i will go to a pleace 

eat niugu feng 

***************************************************  start  *********************


接入流程
1 确保github 里面的Android 和 ios 工程能跑通


Android 接入：
1  把 VoiceSDK 文件夹放入游戏项目中的 Class文件夹下面
2  在src\org\cocos2dx\cpp 路劲下创建文件夹，并放入VoicePlayer.java 和 VoiceRecorder.java 两个文件
3  c++ 调用 java 代码 自定义，可以参考demo
4  VoiceMgr 使用
   VoiceSDK 中的 VoiceMgr 是声音管理类，使用者只需要关心并调用这个类中的相应接口便可 
 
   游戏代码中需要添加
   第一部分：
   1 录音按钮按下  
   VoiceMgr::getInstance()->prepare("record.amr");  //record.amr  名字可以自定义，但需要合法并只定格式：.amr
   2 录音按钮点击取消时
   VoiceMgr::getInstance()->cancel();
   3 录音按钮成功录音 （自定义保护机制，比如少于一秒等。。。）
   VoiceMgr::getInstance()->release();	                                //  录音管理类释放资源
   string msg = VoiceMgr::getInstance()->getVoiceData("record.amr");     //  得到录音数据
   
   // netWork.send(msg) ;   // 这里使用者自定义操作，发送base64编码过后的数据给服务器 
   第二部分：
   当从服务器接受到录音相关的数据时
   1 在回调中添加相关代码
   VoiceMgr::getInstance()->writeVoice("record.amr",testmsg);    
   // 参数1:需要保存的名字（一定要合法且.amr结尾），参数2 从服务器得到的音频数据
   // 这行执行后语音会自动播放
  
   
 ios 接入：
 1  把 VoiceSDK 文件夹放入游戏项目中的 Class文件夹下面
 2  导入 VoiceSDK\ios\lib中的两个静态库libopencore-amrnb.a  和  libopencore-amrwb
 3  voiceMgr 的使用和android 一模一样。
  也就是使用者代码保持一致
   
   
 