console.log("hello from popup.js");
const startButton = document.getElementById("start");

startButton.addEventListener("click", () => {
  navigator.mediaDevices.getUserMedia({ audio: true })
    .then(stream => {
      console.log("Microphone access granted");
      annyang.start();
    })
    .catch(err => {
      console.error("Microphone access denied:", err);
    });
});
