# Lab2-4-Iteratia 2:
- **Acoperire 100% la teste**
- Să compileze fără warninguri cu warning level 4. În VS: 
  - Click dreapta pe proiect -> Properties -> C/C++ -> General: Warning Level = \W4
  - Treat Warnings As Errors = Yes
- Să nu aibă memory leak. Folosiți CRT Library (găsiți în cursul 3 informațiile)
- Modificați în proiect funcția de sortare. Să fie o singură metodă generală de sortare care primește ca parametru o funcție de comparare

# Lab5:
- **Acoperire >=99% la teste**
- Să compileze fără warninguri cu warning level 4. În VS: 
  - Click dreapta pe proiect -> Properties -> C/C++ -> General: Warning Level = \W4
  - Treat Warnings As Errors = Yes
- Să nu aibă memory leak. Folosiți CRT Library (găsiți în cursul 3 informațiile) ✅
- Implementați un nou algoritm de sortare (dacă colegul vostru a implementat în proiectul primit bubble sort, voi puteți face selection sort sau insertion sort sau altceva). Adăugați o opțiune în meniu ca să putem alege algoritmul de sortare dorit. ✅

# Lab6-7-Iteratia1:
- Instalat/activat C++ Core Guideline Checker (vezi curs) și reparat (mai) toate erorile raportate. ✅
- Implementați constructorul de copiere de la clasa din domeniu, în corpul constructorului puneți un `cout` sau `println` (C++ 23). Apoi rulați aplicația și vedeți câte obiecte se creează și dacă sunt prea multe să le reduceți. La print nu ar trebui să aveți ✅

# Lab6-7-It2:
- Code coverage 100%
- No warnings (w4)
- No raw pointers (doar la listă aveți voie)
- No memory leaks
- Activați CPP Guideline Checker - rezolvați tot ce ține de `const` și pointeri
- Creați iterator
- Adăugați lista/vectorul vostru în proiectul VectorDinamicCPP.zip (files) - trebuie să treacă testele de acolo

# Lab8-9-It1:
- No memory leak ✅
- Code coverage 99% ✅
- Fără pointeri ✅
- Fără copii inutile ✅
- Folosiți un dicționar (`map`, `unordered_map`) pentru crearea unui raport. De exemplu: tip produs <-> câte produse de acest tip există. Să fie un raport specific problemei/entității ✅

# Lab8-9-It2:
- No memory leak ✅
- Code coverage 99% ✅
- No warnings (w4) ✅
- Creați o clasă pur abstractă `Repo` și un nou repo. Aplicația trebuie să pornească și cu acest repo, pe lângă cel pe care îl aveți (pe rând). Repo nou să țină datele într-un dicționar (`map`, `unordered_map`). La constructor să primească o probabilitate (o valoare între 0 și 1) și dacă apelăm orice metodă din repo, metoda să arunce exceptie cu probabilitatea dată. ✅

# Lab10-11-It1:
- Code coverage 99%
- La deschiderea ferestrei pe partea dreaptă să apară butoane pentru fiecare tip de produs existent în aplicație (produs este un exemplu, fiecare folosește ce entitate are, puteți folosi raportul făcut de voi la alt lab). La deschiderea ferestrei se adaugă dinamic butoane în funcție de ce produse există deja în aplicație (similar la celelalte enunțuri, ex. la filme să fie buton pentru fiecare gen existent, etc.). La apăsarea butonului să se deschidă un `MessageBox` în care să apară numărul de produse de tipul respectiv.

# Lab10-11-It2:
- Dacă aveți în fereastră listă, înlocuiți-o cu un tabel
- Dacă aveți în fereastră tabel, adăugați lângă o listă
