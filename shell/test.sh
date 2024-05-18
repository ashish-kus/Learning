#!/bin/bash
CONFIG_FILE="~/.config/create_ap/create_ap.conf"

check() {
  command -v "$1" >/dev/null 2>&1
}

notify() {
    check notify-send && notify-send "$@" || echo "$@"
}

if ! command -v create_ap &>/dev/null; then
    notify "Error: create_ap is not installed. Please install it first."
    exit 1
fi

if [ "$EUID" -ne 0 ]; then
    notify "Error: This script must be run as root."
    exit 1
fi

create_access_point() {
    local config_file="$CONFIG_FILE"
    echo "$config_file"

    # Check if the configuration file exists
    if [ -f "$config_file" ]; then
        local wifi_interface
        local internet_interface
        local ssid
        local password

        wifi_interface=$(jq -r '.wifi_interface' "$config_file")
        internet_interface=$(jq -r '.internet_interface' "$config_file")
        ssid=$(jq -r '.ssid' "$config_file")
        password=$(jq -r '.password' "$config_file")

        # Create access point
        create_ap "$wifi_interface" "$internet_interface" "$ssid" "$password"
    else
        notify "Error: Config file not found"
    fi
}



# Function to check and kill create_ap processes
kill_create_ap() {
    if pgrep -x "create_ap" >/dev/null; then
        pkill create_ap
        notify "create_ap processes killed"
    else
        notify "No create_ap processes found"
    fi
}

toggle_access_point() {
    if pgrep -x "create_ap" >/dev/null; then
        pkill create_ap
        notify "create_ap processes killed"
    else
        create_access_point
    fi
}

setIcon() {
    if pgrep -x "create_ap" >/dev/null; then
        icon=""
    else
        icon=""
    fi
}

waybar_output() {
    setIcon
    cat <<EOF
{ "text": "$icon", "tooltip": "Access Point: $icon" }
EOF
}

# Parse command-line options
while getopts ":ctwk:" opt; do
    case ${opt} in
        c )
            create_access_point
            ;;
        t )
            toggle_access_point
            ;;
        w )
            waybar_output
            ;;
        k )
            kill_create_ap
            ;;
        \? )
            echo "Invalid option: -$OPTARG" >&2
            exit 1
            ;;
        : )
            echo "Option -$OPTARG requires an argument." >&2
            exit 1
            ;;
    esac
done
shift $((OPTIND -1))


