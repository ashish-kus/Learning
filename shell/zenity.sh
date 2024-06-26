#!/bin/bash

# Default values
WIFI_INTERFACE="wlan0"
SHARE_INTERFACE="eth0"
SSID="MyHotspot"
PASSPHRASE="12345678"
CHANNEL="default"
ACTION="toggle"

# Function to start the hotspot
start_hotspot() {
    echo "Starting hotspot..."
    if [ "$CHANNEL" == "default" ]; then
        sudo create_ap $WIFI_INTERFACE $SHARE_INTERFACE $SSID $PASSPHRASE
    else
        sudo create_ap -c $CHANNEL $WIFI_INTERFACE $SHARE_INTERFACE $SSID $PASSPHRASE
    fi
}

# Function to stop the hotspot
stop_hotspot() {
    echo "Stopping hotspot..."
    sudo pkill create_ap
}

# Function to toggle the hotspot
toggle_hotspot() {
    if pgrep -x "create_ap" > /dev/null; then
        stop_hotspot
    else
        start_hotspot
    fi
}

# Display a form to the user using zenity
form_output=$(zenity --forms --title="Hotspot Toggle" --text="Enter Hotspot Details" \
    --add-entry="Wi-Fi Interface (default: wlan0)" \
    --add-entry="Share Interface (default: eth0)" \
    --add-entry="SSID (default: MyHotspot)" \
    --add-entry="Passphrase (default: 12345678)" \
    --add-entry="Channel (default: auto)" \
    --add-combo="Action" --combo-values="toggle|start|stop")

if [ $? -eq 0 ]; then
    IFS="|" read WIFI_INTERFACE SHARE_INTERFACE SSID PASSPHRASE CHANNEL ACTION <<< "$form_output"

    # Use default values if inputs are empty
    WIFI_INTERFACE=${WIFI_INTERFACE:-wlan0}
    SHARE_INTERFACE=${SHARE_INTERFACE:-eth0}
    SSID=${SSID:-MyHotspot}
    PASSPHRASE=${PASSPHRASE:-12345678}
    CHANNEL=${CHANNEL:-default}
    ACTION=${ACTION:-toggle}

    # Execute the action
    case $ACTION in
        start)
            start_hotspot
            ;;
        stop)
            stop_hotspot
            ;;
        toggle)
            toggle_hotspot
            ;;
        *)
            zenity --error --text="Invalid action: $ACTION"
            ;;
    esac
else
    zenity --error --text="No input provided, exiting."
    exit 1
fi

exit 0
