



getval(){
  value=$(cat $1 2>/dev/null || echo "error")
  # nandu
  echo $value
}

getval ./catt.sh

