# ProcFS---Operating-Systems-Team-Project

- am creat o structura pentru a retine toate datele despre un proces

- proiectul contine cate o functie pentru citirea tuturor datelor 

- deschidem fisierul cu statistici dat de ps -aux

- deschidem fisierul cu pid si ppid dat de ps xao pid,ppid

- vectorul proces_fct_pid retine pe pozitia pidului indexul sau in
  vectorul de procese

-- functia matriceSuccesori creeaza matricea care ne va ajuta sa 
  accesam arborele 

- fiecare coloana reprezinta un proces
- retinem in matricea succesori, indexul fiecarui fiu de pe coloana i

-- functia itoa converteste un int in char*

-- functia stats construieste un fisier pentru fiecare proces

- parcurgem fiii procesului curent si apelam recursiv functia stats

- pentru fiecare proces, formam noua cale pentru folderul fiului curent
  pe care ulterior o vom trimite in argumentele functiei recursive

- pentru fiecare proces, vom parcurge arborele in adancime, pana la frunze

- vom crea fisierul stats pentru frunze, dupa care ne vom intoarce la parinte, verificam daca mai are fii;
in caz afirmativ, vom merge pana la frunze si vom crea fisierul stats
