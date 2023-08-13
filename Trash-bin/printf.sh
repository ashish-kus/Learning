#!/bin/bash
# #
# name="ashish"
# BF_COL1=2
# COL1=${[3${BF_COL1};}


# printf '%s1m%s[m' "${COL1}" "$name"
#


# name="ashish"
# BF_COL1=2
# COL1="[3${BF_COL1}m"
# COL1=""

# printf '%s%s%s' "${COL1}" "$name" "[m"

. ~/.config/batfetch/config.conf
load_colors(){
  if [[ COLOR = true ]]; then
      BF_COL1=${BF_COL1:-2}
      BF_COL2=${BF_COL2:-7}
      BF_COL3=${BF_COL2:-6}
  else
    BF_COL1=$BF_COL2=$BF_COL3=8
  fi
}
load_colors
echo $BF_COL1
echo $BF_COL2
echo $BF_COL3
