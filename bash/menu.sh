#!/bin/bash
#

function prompt(){
  # local args=($@)
  # local selected_option="$1"
  # local options=(${args[@]:1})
  # local options_length=${#options[@]}

  # echo $selected_option 
  # echo $options 
  # echo $options_length
  # echo $args


  local function_arguments=($@)
	local selected_item="$1"
	local menu_items=(${function_arguments[@]:1})
	local menu_size="${#menu_items[@]}"
	local menu_limit=$((menu_size - 1))

  echo $function_arguments
  echo $selected_item
  echo $menu_items
  echo $menu_size
  echo $menu_limit
}

prompt $@
