all:
	g++ *.cpp -std=c++11 -o trab2
	./trab2 -p publicacoes.csv -q qualis.csv -r regras.csv -d docentes.csv -v veiculos.csv -a 2017
run:
	./trab2 -p publicacoes.csv -q qualis.csv -r regras.csv -d docentes.csv -v veiculos.csv -a 2017
diff:
	diff 1-recredenciamento.csv t/1-recredenciamento.csv -y
	diff 2-publicacoes.csv t/2-publicacoes.csv -y
	diff 3-estatisticas.csv t/3-estatisticas.csv -y