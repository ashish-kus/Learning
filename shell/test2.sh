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
        notify-send "Error: Config file not found"
    fi
}

create_access_point
