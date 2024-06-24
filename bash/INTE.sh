#!/bin/bash
get_network_interfaces() {
    # Use the `ip` command to list all network interfaces
    ip -o link show | awk -F': ' '{print $2}'
}

get_network_interfaces

