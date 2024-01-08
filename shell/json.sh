JSON_OUTPUT=true
log(){

    # Do nothig if info field is empty.
    # [ "$2" ] || return
    name=$1
    {
        set -f
        set +f -- $2
        info=$*
    }
    if [[ $JSON_OUTPUT == true ]]; then
      echo $info
    fi
  }

get_title() {
    user=${USER:-$(id -un)}
    hostname=${HOSTNAME:-${hostname:-$(hostname)}}
    log " " "[3${BF_COL3:-1}m${user}${c8}@[3${BF_COL3:-1}m${hostname}" 
} 
get_model(){
  vandor=$(cat /sys/class/power_supply/BAT*/manufacturer)
  model=$(cat /sys/class/power_supply/BAT*/model_name)
  log "model" "$vandor $model"
}
get_power(){
  powerDraw="$(($(cat /sys/class/power_supply/BAT*/power_now)/1000000))W"
  governer="$(cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor)"
  log "power" "$powerDraw $governer"
}


# shellcheck disable=SC2016
JSON_FORMAT=`{
"tittle": $(get_title),
"model": $(get_model),
"power": $(get_power)
}`

JSON_DATA=$(jq \
--null-input \
--arg title        "${get_title}" \
--arg model        "${model}"     \
--arg power        "${power}"     \
"${JSON_FORMAT}" \
)

# # printf '%s' "${JSON_DATA}"
# get_power
# get_title
# get_model
