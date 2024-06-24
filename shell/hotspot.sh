#!/bin/bash

# Function to display usage
usage() {
    echo "Usage: $0"
    exit 1
}

# Function to prompt user with zenity and fill in the details
prompt_zenity() {
    local mode=$1
    local config_file=$2

    if [ "$mode" == "open" ]; then
        form_output=$(zenity --forms --title="Open AP Configuration" --text="Enter Hotspot Details" \
            --add-entry="Wi-Fi Interface (e.g., wlan0)" \
            --add-entry="Share Interface (e.g., eth0)" \
            --add-entry="SSID (Network name)" \
            --add-entry="Channel (e.g., default or a number)" \
            --add-combo="Action" --combo-values="toggle|start|stop")
    else
        form_output=$(zenity --forms --title="Hotspot Configuration" --text="Enter Hotspot Details" \
            --add-entry="Wi-Fi Interface (e.g., wlan0)" \
            --add-entry="Share Interface (e.g., eth0)" \
            --add-entry="SSID (Network name)" \
            --add-entry="Passphrase" \
            --add-entry="Channel (e.g., default or a number)" \
            --add-combo="Action" --combo-values="toggle|start|stop")
    fi

    if [ $? -eq 0 ]; then
        IFS="|" read WIFI_INTERFACE SHARE_INTERFACE SSID PASSPHRASE CHANNEL ACTION <<< "$form_output"
    else
        zenity --error --text="No input provided, exiting."
        exit 1
    fi

    if [ "$mode" == "open" ]; then
        create_open_config "$config_file"
    else
        create_config "$config_file"
    fi
}

# Function to create config file
create_config() {
    local config_file=$1

    cat <<EOL > "$config_file"
WIFI_INTERFACE=$WIFI_INTERFACE
SHARE_INTERFACE=$SHARE_INTERFACE
SSID=$SSID
PASSPHRASE=$PASSPHRASE
CHANNEL=$CHANNEL
EOL
    echo "Configuration saved to $config_file"
}

# Function to create open config file (no passphrase)
create_open_config() {
    local config_file=$1

    cat <<EOL > "$config_file"
WIFI_INTERFACE=$WIFI_INTERFACE
SHARE_INTERFACE=$SHARE_INTERFACE
SSID=$SSID
PASSPHRASE=""
CHANNEL=$CHANNEL
EOL
    echo "Configuration saved to $config_file"
}

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

# Main script logic
action_prompt=$(zenity --list --title="Hotspot Mode Selection" --text="Choose Hotspot Mode" --radiolist \
    --column "Select" --column "Mode" \
    TRUE "Default AP" \
    FALSE "Personal AP" \
    FALSE "Open AP")

if [ $? -ne 0 ]; then
    zenity --error --text="No selection made, exiting."
    exit 1
fi

case $action_prompt in
    "Default AP")
        CONFIG_FILE="default_ap.conf"
        ;;
    "Personal AP")
        CONFIG_FILE="personal_ap.conf"
        ;;
    "Open AP")
        CONFIG_FILE="open_ap.conf"
        ;;
    *)
        zenity --error --text="Invalid selection, exiting."
        exit 1
        ;;
esac

# Check if config file exists, if not prompt to create it
if [ ! -f "$CONFIG_FILE" ]; then
    if [ "$action_prompt" == "Open AP" ]; then
        prompt_zenity "open" "$CONFIG_FILE"
    else
        prompt_zenity "personal" "$CONFIG_FILE"
    fi
fi

# Load config file
source "$CONFIG_FILE"

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
        exit 1
        ;;
esac

exit 0
