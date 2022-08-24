shuf_5() 
{
  cmd="shuf next-host-pool"
  for i in {1..5}
  do
    cmd="shuf <($cmd)"
  done
  eval $cmd
}

shuf_5 | shuf -n 1

