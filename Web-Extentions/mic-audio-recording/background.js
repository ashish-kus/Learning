let recorder;
let data = [];

chrome.runtime.onMessage.addListener(async (message, sender, sendResponse) => {
  if (message.type === 'start-recording') {
    startRecording();
  } else if (message.type === 'stop-recording') {
    stopRecording();
  }
});

async function startRecording() {
  try {
    const stream = await navigator.mediaDevices.getUserMedia({ audio: true });
    recorder = new MediaRecorder(stream);

    recorder.ondataavailable = (event) => {
      if (event.data.size > 0) {
        data.push(event.data);
      }
    };

    recorder.onstop = () => {
      const audioBlob = new Blob(data, { type: 'audio/webm' });
      const audioUrl = URL.createObjectURL(audioBlob);
      chrome.storage.local.set({ audioUrl: audioUrl });
      data = [];
    };

    recorder.start();
  } catch (err) {
    console.error('Error accessing microphone:', err);
  }
}

function stopRecording() {
  if (recorder) {
    recorder.stop();
  }
}

