#pragma once
#include "stdafx.h"
#include "AbstractChubEngine.h"

#if defined(BILLGATES)

 #pragma once
 #include "MultiplexPotentiator.h"
 #include "stdafx.h"
 class GwonzoSound {
 private:
 HWAVEOUT hwv;
 MMTIME twonk;
 #define BIFFER_AMT 10
 int gonzo_plax;
 #define BIFFERSIZ 400
 DWORD lastsample;
 int sample_rate;
 UINT wReturn; 
 WAVEFORMATEX pcmWaveFormat; 
 WAVEHDR gonzChong[BIFFER_AMT];
 AbstractChubEngine * mime;
 char bifferio[BIFFER_AMT][BIFFERSIZ*4];
 public:

 GwonzoSound(AbstractChubEngine * m) {
  lastsample = 0;
  mime = m;
  if (GoncoCheck(44100))
   sample_rate = GoncOpenlus();
  else if (GoncoCheck(22050))
   sample_rate = GoncOpenlus();
  else if (GoncoCheck(11025))
   sample_rate = GoncOpenlus();
  else if (GoncoCheck(8000))
   sample_rate = GoncOpenlus();
  ///mime->setSampleRate(sample_rate);
  for (int i = 0; i < BIFFER_AMT; i++) {
   gonzChong[i].lpData = bifferio[i];
   gonzChong[i].dwBufferLength = BIFFERSIZ*4;
   gonzChong[i].dwFlags = 0;
   gonzChong[i].dwUser = i;
  }
  twonk.wType = TIME_SAMPLES;
  for (int i = 0; i < BIFFER_AMT-3; i++) 
   GonzoSound();
  lastsample += BIFFERSIZ;
 }

 int GoncoCheck(DWORD sr) {
  pcmWaveFormat.wFormatTag = WAVE_FORMAT_PCM; 
  pcmWaveFormat.nChannels = 2; 
  pcmWaveFormat.nSamplesPerSec = sr; 
  pcmWaveFormat.nAvgBytesPerSec = sr*4; 
  pcmWaveFormat.nBlockAlign = 4; 
  pcmWaveFormat.wBitsPerSample = 16; 
  pcmWaveFormat.cbSize = 0;
  wReturn = waveOutOpen (NULL,WAVE_MAPPER, &pcmWaveFormat,NULL,NULL,WAVE_FORMAT_QUERY);
  return (wReturn == 0);
 }

 DWORD GoncOpenlus() {
  waveOutOpen((LPHWAVEOUT)&hwv, WAVE_MAPPER, &pcmWaveFormat, NULL, NULL, CALLBACK_NULL);
  gonzo_plax = 0;
  return pcmWaveFormat.nSamplesPerSec;
 }

 int GonzoSound () { 
  if (gonzChong[gonzo_plax].dwFlags == WHDR_INQUEUE) {
   //if (++gonzo_plax>=BIFFER_AMT) gonzo_plax =0;
   return 0;
  }
  else if (gonzChong[gonzo_plax].dwFlags != WHDR_INQUEUE) {
   gonzChong[gonzo_plax].dwFlags = 0;
   int skiplown = 0;
   for (skiplown = 0; skiplown < BIFFERSIZ; skiplown++) {
    int * resin;
    if (mime) {
     resin = mime->gingness(skiplown, BIFFERSIZ);
     //#define KOMPRESSOR(chb) \
     //if(chb>126)chb=126;if(chb<-126)chb=-126;
     #define KOMPRESSOR(chb) \
     if(chb>32000)chb=32000;if(chb<-32000)chb=-32000;
     resin[0] >>= 4;
     resin[1] >>= 4;
     KOMPRESSOR(resin[0])
     KOMPRESSOR(resin[1])
     bifferio[gonzo_plax][skiplown*4] = (char)(resin[0]);
     bifferio[gonzo_plax][(skiplown*4)+1] = (char)((resin[0]>>8));
     bifferio[gonzo_plax][(skiplown*4)+2] =(char)(resin[1]);
     bifferio[gonzo_plax][(skiplown*4)+3] =  (char)((resin[1]>>8));
   
    }
   }
   waveOutPrepareHeader(hwv, &gonzChong[gonzo_plax], sizeof(WAVEHDR)); 
   waveOutWrite(hwv, &gonzChong[gonzo_plax], sizeof(WAVEHDR)); 
   abstr->beging();
   if (++gonzo_plax>=BIFFER_AMT) gonzo_plax =0;
  } return 1;
 }

 void increment() { 
  //lastsample=twonk.u.sample;}
  lastsample += BIFFERSIZ; }

 int GonzoTimeCheck() {
  waveOutGetPosition(hwv, &twonk, sizeof(MMTIME) ); 
  return twonk.u.sample > lastsample;
  //return (gonzChong[gonzo_plax].dwFlags != WHDR_INQUEUE);
 }
 
 };




#elif defined(STEVEJOBS)

#define CA_BUFF_MAX  (1024)
#define SAMPLE_RATE  (44100)
#define MAX_PLAY_BUFFS  (4)

int CAStartPlayback(int channels, long buffFrames);
int CAStopPlayback();
int CAPlayBuffer();
void doBuff();

static OSStatus appOutputIOProc (AudioDeviceID  inDevice, const AudioTimeStamp*  inNow, const AudioBufferList*   inInputData, 
         const AudioTimeStamp*  inInputTime, AudioBufferList*  outOutputData, const AudioTimeStamp* inOutputTime, 
         void* defptr);

static AudioDeviceID  playDevice;    /* the device we play from  */
static UInt32   playDeviceBufferSize; // bufferSize returned by kAudioDevicePropertyBufferSize
static AudioStreamBasicDescription playDeviceFormat; // info about the default device
static AudioStreamBasicDescription playDeviceFormatOutt; // info about the default device
static char   playing;
static long   deviceBufferFrames;  /* how many frames per buffer  */
static int   playDeviceChannels;


int CAStartPlayback(int channels, long buffFrames){
    OSStatus   err = kAudioHardwareNoError; 
 UInt32    count;
 playDevice = kAudioDeviceUnknown;
 count = sizeof(playDevice);  // it is required to pass the size of the data to be returned
 if ((err = AudioHardwareGetProperty(kAudioHardwarePropertyDefaultOutputDevice,  
     &count, (void *) &playDevice))!=kAudioHardwareNoError) return(0);
 count = sizeof(playDeviceBufferSize); // it is required to pass the size of the data to be returned
 playDeviceBufferSize = buffFrames * sizeof(float) * channels;  /* set to requested size */
 if ((err = AudioDeviceSetProperty(playDevice, 0, 0, false, kAudioDevicePropertyBufferSize, 
     count, &playDeviceBufferSize))!=kAudioHardwareNoError) return(0);
 count = sizeof(playDeviceBufferSize); // it is required to pass the size of the data to be returned
 if ((err = AudioDeviceGetProperty(playDevice, 0, false, kAudioDevicePropertyBufferSize, 
     &count, &playDeviceBufferSize))!=kAudioHardwareNoError) return(0);
 count = sizeof(playDeviceFormat); // it is required to pass the size of the data to be returned
 if ((err = AudioDeviceGetProperty(playDevice, 0, false, kAudioDevicePropertyStreamFormat, 
     &count, &playDeviceFormat))!=kAudioHardwareNoError) return(0);
 
 
 //if (playDeviceFormat.mFormatID != kAudioFormatLinearPCM) return(0);
 //if (!(playDeviceFormat.mFormatFlags & kLinearPCMFormatFlagIsFloat)) return(0);
 playDeviceFormat.mSampleRate = SAMPLE_RATE;
 playDeviceFormat.mFormatID = kAudioFormatLinearPCM;
 playDeviceFormat.mFormatFlags = kAudioFormatFlagsCanonical;
 //playDeviceFormat.mFormatFlags = kAudioFormatFlagsNativeEndian | kAudioFormatFlagIsPacked;
 playDeviceFormat.mBytesPerPacket = 8;
 playDeviceFormat.mFramesPerPacket = 1;
 playDeviceFormat.mBytesPerFrame = 8;
 playDeviceFormat.mChannelsPerFrame = 2;
 playDeviceFormat.mBitsPerChannel = 32;
 count = sizeof(playDeviceFormat);
 err = AudioDeviceSetProperty(playDevice, 0, 0, 0, kAudioDevicePropertyStreamFormat, count, &playDeviceFormat);
 if (err != kAudioHardwareNoError);
 if ((err = AudioDeviceGetProperty(playDevice, 0, false, kAudioDevicePropertyStreamFormat, 
           &count, &playDeviceFormatOutt))!=kAudioHardwareNoError) return(0);
 
 deviceBufferFrames = playDeviceBufferSize/(sizeof(float)*channels);
 playDeviceChannels = channels;
 

        if (AudioDeviceAddIOProc(playDevice, 
          appOutputIOProc, NULL)!=kAudioHardwareNoError)  return(0);
  if (AudioDeviceStart(playDevice, 
         appOutputIOProc)!=kAudioHardwareNoError) return(0);
        playing = 1;
    //doBuff();
    return(1);
}

int CAStopPlayback() {
    long err;
    if (!playing) return(0);    
    playing = 0; 
    if ((err = AudioDeviceStop(playDevice, 
          appOutputIOProc))!=kAudioHardwareNoError) return(0);
    if ((err = AudioDeviceRemoveIOProc(playDevice, 
            appOutputIOProc))!=kAudioHardwareNoError) return(0);
    return(1);
}

static OSStatus appOutputIOProc (AudioDeviceID  inDevice, 
         const AudioTimeStamp*  inNow, 
         const AudioBufferList*   inInputData, 
         const AudioTimeStamp*  inInputTime, 
         AudioBufferList*  outOutputData, 
         const AudioTimeStamp* inOutputTime, 
         void* defptr) {
#pragma unused(inDevice, inNow, inInputData, inInputTime, defptr)
 float  *outus = (float*)(outOutputData->mBuffers[0].mData);
 int  numFrames = outOutputData->mBuffers[0].mDataByteSize / (sizeof(float)*2);
 if (!playing) {
  
  if (AudioDeviceAddIOProc(playDevice, appOutputIOProc, NULL)!=kAudioHardwareNoError)  return(0);
  if (AudioDeviceStart(playDevice, appOutputIOProc)!=kAudioHardwareNoError) return(0);
  
 }
 //AudioDeviceStart(playDevice, appOutputIOProc);
 int * acc;
 for(int i=0; i<numFrames; i++) {
  acc = abstr->gingness(i, numFrames);
  *outus++ = (float)(acc[0]) / (256*259);
  if (*outus > 1) *outus = 1;
  *outus++ = (float)(acc[1]) / (256*259);
  if (*outus > 1) *outus = 1;
 }
 abstr->beging();
 return kAudioHardwareNoError;  
}
#elif defined(LINUSTORWALDS)

#define BUFSIZE 8192
 unsigned int rate = 22050; /* Sample rate */
 int exact_rate;  
 int dir;    
 unsigned int periods = 2;      
 snd_pcm_uframes_t periodsize = 1024; /* Periodsize (bytes) */     
 
 snd_pcm_hw_params_t *hwparams;
 snd_pcm_sw_params_t *sw_params;
    char *pcm_name;
    snd_pcm_t *playback_handle;
    unsigned char *data;
    int pcmreturn, l1, l2;
    short s1, s2;
    int frames;
 
void open_pcm() {
 int val;
 for (val = 0; val <= SND_PCM_STREAM_LAST; val++)
 printf("  %s\n", snd_pcm_stream_name((snd_pcm_stream_t)val));
 pcm_name = strdup("default");
 snd_pcm_hw_params_t *hw_params;
 if (snd_pcm_open (&playback_handle, "default", SND_PCM_STREAM_PLAYBACK, 0) < 0) {
  printf ("cannot open audio device %s\n", pcm_name);
  exit (1);
 } printf ("PCMopend\n");
 snd_pcm_hw_params_alloca(&hw_params);
 snd_pcm_hw_params_any(playback_handle, hw_params);
 snd_pcm_hw_params_set_access(playback_handle, hw_params, SND_PCM_ACCESS_RW_INTERLEAVED);
 snd_pcm_hw_params_set_format(playback_handle, hw_params, SND_PCM_FORMAT_S16_LE);
 snd_pcm_hw_params_set_rate_near(playback_handle, hw_params, &rate, 0);
 snd_pcm_hw_params_set_channels(playback_handle, hw_params, 2);
 snd_pcm_hw_params_get_periods(hw_params, &periods, 0);
 printf("%d periods\n", periods );
 //snd_pcm_hw_params_set_periods(playback_handle, hw_params, periods, 0);
 //snd_pcm_hw_params_set_period_size(playback_handle, hw_params, periodsize, 0);
 snd_pcm_hw_params_set_buffer_size(playback_handle, hw_params, (periodsize * periods)>>1);
 val = snd_pcm_hw_params(playback_handle, hw_params);
 //snd_pcm_hw_params_set_buffer_size
 if (val < 0) printf("errueur setting parmscheeze\n");
 snd_pcm_sw_params_alloca(&sw_params);
 snd_pcm_sw_params_current(playback_handle, sw_params);
 snd_pcm_sw_params_set_start_threshold(playback_handle, sw_params, (periodsize * periods)>>1);
 snd_pcm_sw_params_set_avail_min(playback_handle, sw_params, (periodsize * periods));
 snd_pcm_sw_params(playback_handle, sw_params);
    //return(playback_handle);
 data = (unsigned char *)malloc(periodsize);
 frames = periodsize >> 2;
 snd_pcm_prepare(playback_handle);
 pcmreturn = snd_pcm_writei(playback_handle, data, frames);
 pcmreturn = snd_pcm_start(playback_handle);
 //pcmreturn = snd_pcm_writei(playback_handle, data, frames);
  //abstr->beging();
  printf("%d\n", pcmreturn);
  if (pcmreturn<0) snd_pcm_prepare(playback_handle);
}

void pcm_runnus(signed char *gwonz) {
 unsigned long avail;//snd_pcm_sframes_t avail;
 avail = snd_pcm_avail(playback_handle);
 //printf("%d\n", avail);
 signed int * outus;
 while (avail >= frames) {
  //printf("chonk");
  for(l2 = 0; l2 < frames; l2++) {
   outus = abstr->gingness(l2,frames);
   #define KOMPRESSOR(chb) \
     if(chb>126)chb=126;if(chb<-126)chb=-126;
          //s1 = (l2 % (gwonz[1]+200)) * 100 - 5000;  
          //s2 = (l2 % (gwonz[0]+278)) * 100 - 5000;  
   outus[0] >>=4; outus[1] >>=4;
   data[4*l2] = (unsigned char)outus[0];
   data[4*l2+2] = (unsigned char)outus[1];
   outus[0] >>=8; outus[1] >>=8;
   KOMPRESSOR(outus[0]);KOMPRESSOR(outus[1])
   data[4*l2+1] = outus[0];
   data[4*l2+3] = outus[1];
  }
  pcmreturn = snd_pcm_writei(playback_handle, data, frames);
  abstr->beging();
  //printf("%d\n", pcmreturn);
  if (pcmreturn<0) snd_pcm_prepare(playback_handle);
 
  //printf("%d\n", pcmreturn);
  avail = snd_pcm_avail_update(playback_handle);
 } //if (avail < frames) snd_pcm_prepare(pcm_handle);
}

void pcm_closz() {
    snd_pcm_drain(playback_handle);
    snd_pcm_close(playback_handle);
}
#endif
