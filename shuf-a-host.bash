shuf_5() 
{
  cmd="shuf next-host-pool"
  for i in {1..5}
  do
    cmd="shuf <($cmd)"
  done
  eval $cmd
}

for i in $(seq 1 10); do
     msg=$(shuf -n 1 teasing-messages)
     candidate=$(shuf -n 1 next-host-pool)
     echo -ne "$msg ---- $candidate\033[0K\r"
     sleep 1
done

echo "And it is official, congratulations: $(shuf_5 | shuf -n 1)"

