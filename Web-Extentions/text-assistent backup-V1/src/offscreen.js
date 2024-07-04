chrome.runtime.onMessage.addListener(async (message) => {
    // Check if the message is intended for the offscreen document
    if (message.target === 'offscreen') {
        // Perform actions based on the message type
        switch (message.type) {
            case 'start-recording':
                // Start recording if the message type is 'start-recording'
                startRecording(message.data);
                break;
            case 'stop-recording':
                // Stop recording if the message type is 'stop-recording'
                stopRecording();
                break;
            default:
                // Throw an error for any unrecognized message type
                throw new Error('Unrecognized message:', message.type);
        }
    }
});

let recorder; // This will hold the MediaRecorder instance
let data = []; // This will store the recorded data

async function startRecording(streamId) {
    // Check if a recording is already in progress
    if (recorder?.state === 'recording') {
        throw new Error('Called startRecording while recording is in progress.');
    }

    // Get the media stream from the browser tab
    const media = await navigator.mediaDevices.getUserMedia({
        audio: {
            mandatory: {
                chromeMediaSource: 'tab',
                chromeMediaSourceId: streamId
            }
        }
    });

    // Play the captured audio for the user
    const output = new AudioContext();
    const source = output.createMediaStreamSource(media);
    source.connect(output.destination);

    // Start recording
    recorder = new MediaRecorder(media, { mimeType: 'audio/webm' });
    recorder.ondataavailable = (event) => data.push(event.data);
    recorder.onstop = () => {
        const blob = new Blob(data, { type: 'audio/webm' });
         window.open(URL.createObjectURL(blob), '_blank');

        // Reset state for the next recording
        recorder = undefined;
        data = [];
    };
    recorder.start();

    // Update the URL to indicate recording is in progress
    window.location.hash = 'recording';
}

async function stopRecording() {
    // Stop the recorder
    recorder.stop();
  
    // Stop all tracks to remove the recording icon in the tab
    recorder.stream.getTracks().forEach((t) => t.stop());
  
    // Update the URL to indicate recording has stopped
    window.location.hash = '';
  }
