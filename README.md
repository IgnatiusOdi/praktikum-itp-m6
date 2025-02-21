# praktikum-itp-m6

## Praktikum ITP M6

### No 1

Buatlah permainan type racer sederhana. Berikut merupakan contoh tampilan awal permainan.

```
=== TYPE RACER ===
1. Play
2. High Score
0. Exit
```

PLAY\
Pada menu ini, program akan meminta nama player lalu merandom 5-10 kata dari dictionary yang terdaftar (dictionary pada permainan ini hanya terdapat 10 kata yaitu PRAKTIKUM, WEEK, ENAM, LAB, EMPAT, MATERI, TUGAS, TENTANG, ARRAY, STRING). Setiap kata tersebut akan dipisahkan dengan spasi dan akan menjadi suatu kalimat. Randomlah setiap huruf pada kata agar setiap kata terdiri dari huruf besar dan kecil. Setelah program menampilkan kalimat hasil randoman, program akan meminta inputan terus menerus hingga player berhasil menyelesaikan kalimat tersebut. Player akan menginputkan kata dan program akan mengecek apakah kata yang diinputkan sesuai dengan giliran kata dari kalimat tersebut (case sensitive). Jika salah maka program tetap akan meminta inputan dengan pengecekan kata tersebut. Berikut merupakan contoh permainan. (Tampilkan timer second juga untuk mengetahui berapa lama player dapat menyelesaikan kalimat tersebut, gunakan system cls!)

```
Nama Player : Laa Miao Miao

===== CIAYO GUYS! =====
Player : Laa Miao Miao
Timer  : 20
Salah  : 2

WEeK eNaM MATeri arraY string
Kata ke 1 : week
Kata ke 1 : WEeK
Kata ke 2 : eNaM
Kata ke 3 : materi
Kata ke 3 : MATeri
Kata ke 4 : array
Kata ke 5 : string

Selamat Laa Miao Miao, anda berhasil menyelesaikan kalimat sepanjang 5
kata dalam waktu 20 detik dengan kesalahan menulis sebanyak 2x !
```

HIGH SCORE\
Pada menu ini tampilkan semua data player yang sudah bermain. Data akan ditampilkan urut berdasarkan timer terkecil hingga terbesar. Berikut merupakan contoh tampilan.

```
=== HIGH SCORE ===

1. Laa Miao Miao
   Timer : 20
   Word : 5
   Salah : 2

2. Meiana
   Timer : 50
   Word : 9
   Salah : 10
```

EXIT\
Program akan berhenti berjalan.

### Tugas

Buatlah permainan sambung kata sederhana. Berikut merupakan contoh tampilan permainan.

```
=== PLAY WITH WORDS ===
1. Play
2. Dictionary
3. High Score
0. Quit
```

QUIT\
Program akan berhenti berjalan.

PLAY\
Player dapat bermain kata dengan memilih menu ini. Saat player memilih menu ini, program akan meminta nama player dan setelah itu program akan menampilkan arena kotak-kotak yang dapat diisi huruf pada setiap kotaknya. Besar arena didapatkan dari kata terpanjang yang telah terdaftar di dictionary. Player dapat memasukkan kata ke dalam kotak jika kata tersebut telah terdaftar di dalam dictionary (jika kata tidak terdaftar atau panjang kata yang di masukkan tidak match dengan arena / huruf yang berada di arena maka tampilkan pesan gagal menginputkan kata beserta alasannya). Jika kata berhasil dimasukkan ke dalam arena, maka player akan mendapatkan score 20 per huruf (Kata hanya dapat dimasukkan ketika match kecuali saat pertama kali menaruh kata ke arena). Permainan akan berakhir ketika player menginputkan “EXIT GAME” atau ketika arena sudah tidak dapat dimasukkan kata apapun lagi ke dalam arena (kata yang sudah terdaftar di dictionary!). Ketika permainan berakhir maka catatlah nama player beserta score dan total word ke dalam high score. Format memasukkan kata ke dalam arena adalah (jika format salah maka tampilkan pesan format penulisan salah)

```
[kata]_[koordinaStarttX],[koordinatStartY]_[DOWN/DOWN]
```

Berikut merupakan contoh dari permainan. (contoh kata terpanjang di dictionary adalah “PRAKTIKUM” yang terdiri dari 9 huruf)

image.png

DICTIONARY\
Pada menu ini player dapat melihat list kata yang terdaftar, menambahkan kata maupun menghapus kata. Pada awal permainan, dictionary akan memiliki 10 kata yang sudah terdaftar yaitu PRAKTIKUM, WEEK, ENAM, LAB, EMPAT, MATERI, TUGAS, TENTANG, ARRAY, STRING. Berikut merupakan menu dictionary yang akan muncul ketika menu dictionary dipilih.

```
=== DICTIONARY ===
1. Lihat Kata
2. Tambah Kata
3. Hapus Kata
0. Back
>>>
```

Lihat Kata\
Menu ini akan menampilkan semua kata yang sudah terdaftar. Berikut merupakan contoh tampilan. (Semua kata wajib dituliskan dalam huruf kapital)

```
=== LIHAT KATA ===
01. PRAKTIKUM
02. WEEK
03. ENAM
04. LAB
05. EMPAT
06. MATERI
07. TUGAS
08. TENTANG
09. ARRAY
10. STRING
```

Tambah Kata\
Menu ini berfungsi untuk menambahkan kata. Pastikan kata yang ditambahkan tidak ada yang kembar dengan kata yang sudah terdaftar, jika gagal maka tampilkan pesan gagal tambah kata beserta alasan (kata bersifat case insensitive). Pastikan juga kata tidak mengandung spasi maupun karakter lain selain huruf. Jika berhasil maka tampilkan pesan berhasil tambah kata. Berikut merupakan contoh tampilan.

```
=== TAMBAH KATA ===
Kata : week
Gagal tambah kata! Kata week sudah terdaftar.
```

Hapus Kata\
Menu ini berfungsi untuk menghapus kata. Pastikan kata yang dihapus ditemukan di dalam dictionary, jika tidak ditemukan maka tampilkan pesan gagal hapus kata berserta alasannya. Jika berhasil menghapus maka hapus lah kata tersebut dari dictionary. Berikut merupakan contoh tampilan.

```
=== HAPUS KATA ===
Kata : weeks
Gagal hapus kata! Kata weeks tidak ditemukan.
```

Back : Kembalikan pada menu utama.
HIGH SCORE
Pada menu ini tampilkan semua data player yang sudah bermain. Data akan ditampilkan urut berdasarkan score terbesar hingga terkecil. Berikut merupakan contoh tampilan.

```
=== HIGH SCORE ===
1. Laa Miao Miao
   Score : 700
   Word  : 20

2. Meiana
   Score : 520
   Word  : 14
```
