worker:
	g++ -o sat_table_generator sat_table_generator.cpp -g -O2
	g++ -o unsat_table_generator unsat_table_generator.cpp -g -O2
	g++ -o cnf_generator cnf_generator.cpp -g -O2