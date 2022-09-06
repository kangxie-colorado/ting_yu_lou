shuf_n() 
{
  n=$1
  cmd="shuf next-host-pool"
  for i in $(seq 1 $n)
  do
    cmd="shuf <($cmd)"
  done
  eval $cmd
}

green="0;32"
bold=$(tput bold)
normal=$(tput sgr0)

echo "********************************************************************************"
echo "*      听 雨 楼 - 抽签仪式                                                     *"
echo "*                                                                              *"

for i in $(seq 1 8); do
     msg=$(shuf -n 1 teasing-messages)
     candidate=$(shuf -n 1 next-host-pool)
     color=$(shuf -n 1 colors)
     echo -ne "\033[${color}m*      $msg ---- $candidate                                           \033[0K\r"
     sleep 2
done

echo "*                                                                              *"
echo -e "\033[${green}m${bold}*      签落谁家，自有分晓，恭喜: $(shuf_n 10 | shuf -n 1)              "
echo "${normal}********************************************************************************"

