projectName = icpc-trd

gen:
	xelatex -jobname=$(projectName) main.tex
	xelatex -jobname=$(projectName) main.tex
	xelatex -jobname=$(projectName) main.tex