#!/bin/bash
  charge="$(cat /sys/class/power_supply/BAT*/capacity)%"
  Energy_now="$(cat /sys/class/power_supply/BAT*/energy_now)"
  Draw="$(cat /sys/class/power_supply/BAT*/power_now)"

  if [ $Draw = 0 ]; then
      ESTIMATION="AC pluged "
      echo "000000" > nan
  else
      time=$(echo "scale=4; $Energy_now / $Draw" | bc)
      hours=${time%.*}
      decimal_part=$(echo "$time" | cut -d '.' -f 2)
      minutes=$((decimal_part * 60 / 10000))
      ESTIMATION="${hours}h ${minutes}m"
  fi
  echo "charge $charge $ESTIMATION"

