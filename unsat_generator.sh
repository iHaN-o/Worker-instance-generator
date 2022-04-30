./unsat_table_generator $1 $2 $3 $4 > table.txt
cnfname="worker_"$1"_"$2"_"$3"_"$4".cnf"
./cnf_generator $1 $2 $3 table.txt > $cnfname