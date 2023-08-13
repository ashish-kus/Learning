#!/bin/bash

# --config /path/to/config.conf
if [[ -f "$config_file" ]]; then
    source "$config_file"
    return

elif [[ -f "${XDG_CONFIG_HOME}/neofetch/config.conf" ]]; then
    source "${XDG_CONFIG_HOME}/neofetch/config.conf"

elif [[ -f "${XDG_CONFIG_HOME}/neofetch/config" ]]; then
    source "${XDG_CONFIG_HOME}/neofetch/config"

elif [[ -z "$no_config" ]]; then
    config_file="${XDG_CONFIG_HOME}/neofetch/config.conf"

    # The config file doesn't exist, create it.
    mkdir -p "${XDG_CONFIG_HOME}/neofetch/"
    printf '%s\n' "$config" > "$config_file"
fi
