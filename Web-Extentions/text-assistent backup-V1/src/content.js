console.log("content.js --> hello");
window.bubbleId = "Hiremate-bubble";
window.bubble = document.getElementById(window.bubbleId);

if (window.bubble) {
    console.log("HireMate bubble element found");
} else {

    const bubble = document.createElement('div');
    bubble.id = window.bubbleId; // Ensuring the button has the correct ID
    bubble.style.position = 'fixed';
    bubble.style.bottom = '400px';
    bubble.style.right = '20px';
    bubble.style.width = '60px';
    bubble.style.height = '60px';
    bubble.style.borderRadius = '50%';
    bubble.style.backgroundColor = '#FF0000';
    bubble.style.display = 'flex';
    bubble.style.alignItems = 'center';
    bubble.style.justifyContent = 'center';
    bubble.style.zIndex = '1000';
    document.body.appendChild(bubble);

    // Creating and styling the bubble
    const button = document.createElement('div');
    button.style.position = 'absolute';
    button.style.cursor = 'pointer';
    button.style.bottom = '5px';
    button.style.right = '5px';
    button.style.width = '50px';
    button.style.height = '50px';
    button.style.borderRadius = '50%';
    button.style.backgroundColor = '#007AFF';
    button.style.display = 'flex';
    button.style.alignItems = 'center';
    button.style.justifyContent = 'center';
    button.style.zIndex = '1000';
    bubble.appendChild(button);

    // Create and style the exclamation mark
    const exclamation = document.createElement('div');
    exclamation.innerText = '!';
    button.style.cursor = 'pointer';
    exclamation.style.position = 'absolute';
    exclamation.style.top = '-5px';
    exclamation.style.left = '-5px';
    exclamation.style.width = '20px';
    exclamation.style.height = '20px';
    exclamation.style.borderRadius = '50%';
    exclamation.style.backgroundColor = 'red';
    exclamation.style.color = 'white';
    exclamation.style.display = 'flex';
    exclamation.style.alignItems = 'center';
    exclamation.style.justifyContent = 'center';
    exclamation.style.fontSize = '16px';
    exclamation.style.zIndex = '1001';
    bubble.appendChild(exclamation);

    // Create and style the message bubble
    const messageBubble = document.createElement('div');
    messageBubble.innerText = 'Hello, this is your assistant!';
    messageBubble.style.position = 'absolute';
    messageBubble.style.bottom = '65px';
    messageBubble.style.right = '70px';
    messageBubble.style.width = '200px';
    messageBubble.style.padding = '10px';
    messageBubble.style.borderRadius = '10px 10px 0 10px';
    messageBubble.style.backgroundColor = '#007AFF';
    messageBubble.style.color = '#FFFFFF';
    messageBubble.style.boxShadow = '0 0 10px rgba(0,0,0,0.1)';
    messageBubble.style.zIndex = '1000';
    messageBubble.style.display = 'none';
    bubble.appendChild(messageBubble);


    // Create and style the tool tray (list)
    const toolTray = document.createElement('div');
    toolTray.style.position = 'absolute';
    toolTray.style.bottom = '-20px';
    toolTray.style.right = '60px';
    toolTray.style.width = '0'; // Initially hidden
    toolTray.style.height = '50px'; // Adjust the height as needed
    toolTray.style.overflow = 'hidden'; // Hide overflow
    toolTray.style.color = '#FFFFFF';
    toolTray.style.boxShadow = '0 0 10px rgba(0,0,0,0.1)';
    toolTray.style.zIndex = '1000';
    toolTray.style.transition = 'width 0.3s ease-in-out'; // Smooth transition animation
    button.appendChild(toolTray);

    // List of tools (list items)
    const toolsList = document.createElement('ul');

    toolsList.style.listStyleType = 'none';
    toolsList.style.padding = '0';
    toolsList.style.margin = '0';
    toolsList.style.display = 'flex';
    toolsList.style.flexDirection = 'row';
    toolsList.style.justifyContent = 'space-around'; // Adjust as needed
    toolsList.innerHTML = `
        <li style="padding: 5px; background-color: #007AFF; border-radius: 50%; cursor: pointer;  height: 40px; width: 40px"></li>
        <li style="padding: 5px; background-color: #007AFF; border-radius: 50%; cursor: pointer;  height: 40px; width: 40px"></li>
        <li style="padding: 5px; background-color: #007AFF; border-radius: 50%; cursor: pointer;  height: 40px; width: 40px"></li>
        <li style="padding: 5px; background-color: #007AFF; border-radius: 50%; cursor: pointer;  height: 40px; width: 40px"></li>
        <!-- Add more tools as needed --#007AFF>
    `;
    toolTray.appendChild(toolsList);

    button.addEventListener('click', () => {
        console.log("button clicked");
    })

    // Hover effect to show tool tray
    button.addEventListener('mouseenter', () => {
        toolsList.style.transitionDelay = '1s';
        toolTray.style.width = '220px'; // Adjust width to show all items horizontally
    });

    // Hide tool tray on mouse leave
    button.addEventListener('mouseleave', () => {
        toolTray.style.width = '0'; // Hide tool tray by reducing width to 0
    });

    // Toggle message bubble on exclamation mark click
    exclamation.addEventListener('click', () => {
        event.stopPropagation();
        messageBubble.style.display = messageBubble.style.display === 'none' ? 'block' : 'none';
    });

    // Function to make the element draggable along the y-axis
    function makeDraggableY(elmnt, msgBubble) {
        var pos1 = 0, pos3 = 0;
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
            e.preventDefault();
            // Calculate the new cursor position
            pos1 = pos3 - e.clientY;
            pos3 = e.clientY;

            // Set the element's new position
            elmnt.style.bottom = (parseInt(elmnt.style.bottom, 10) + pos1) + "px";
            // Update message bubble position
        }

        function closeDragElement() {
            document.onmouseup = null;
            document.onmousemove = null;
        }
    }
    makeDraggableY(bubble); // Make the button draggable along the y-axis and move message bubble along with it
}
