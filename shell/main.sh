main(){
  set -f
  set +f ascii title model charge power state health  
  for nandu; do echo $nandu; done
  }
  echo ""
main "$@"
