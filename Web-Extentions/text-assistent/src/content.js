console.log("content.js --> hello");
window.bubbleId = "Hiremate-bubble";
window.bubble = document.getElementById(window.bubbleId);

if (window.bubble) {
    console.log("HireMate bubble element found");
} else {
    // Creating and styling the bubble
    const button = document.createElement('div');
    button.id = window.bubbleId; // Ensuring the button has the correct ID
    button.style.position = 'fixed';
    button.style.bottom = '20px';
    button.style.right = '20px';
    button.style.width = '70px';
    button.style.height = '70px';
    button.style.borderRadius = '50%';
    button.style.backgroundColor = '#007AFF';
    button.style.display = 'flex';
    button.style.alignItems = 'center';
    button.style.justifyContent = 'center';
    button.style.cursor = 'pointer';
    button.style.zIndex = '1000';
    document.body.appendChild(button);

    // Function to make the element draggable along the y-axis
    function makeDraggableY(elmnt) {
        var pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0;
        elmnt.onmousedown = dragMouseDown;

        function dragMouseDown(e) {
            e = e || window.event;
            e.preventDefault();
            pos3 = e.clientY; // Get the initial mouse cursor position
            document.onmouseup = closeDragElement;
            document.onmousemove = elementDrag;
        }

        function elementDrag(e) {
            e = e || window.event;
            e.preventDefault();            // Calculate the new cursor position
            pos1 = pos3 - e.clientY;
            pos3 = e.clientY;            // Set the element's new position
            elmnt.style.bottom = (parseInt(elmnt.style.bottom, 10) + pos1) + "px";
        }
        function closeDragElement() {
            document.onmouseup = null;
            document.onmousemove = null;
        }
    }
    makeDraggableY(button); // Make the button draggable along the y-axis

    // Adding event listener for the button (example commented out)
    // button.addEventListener('click', () => {
    //     chrome.runtime.sendMessage({ action: 'toggleRecording' });
    // });

    // Handling messages from the background script to update the UI (example commented out)
    // chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
    //     if (message.action === 'updateUI') {
    //         const { data } = message;
    //         button.style.backgroundColor = data.color; // Change button color based on response
    //         button.title = data.text; // Show response text on hover
    //     }
    // });
}

