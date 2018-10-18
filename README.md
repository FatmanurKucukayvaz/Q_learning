# Q_learning
Q-learning uygulaması kullanılarak labirentte yol bulma işlemi yapıldı. Verilen input dosyalarında hangi odaların hangilerine komşu olduğu bilgisi bulunmaktadır. Bu komşulukları kullanarak bir R matrisi tanımlayıp bu matrise komşu olan odaların kesiştikleri yerlere 0 komşulukları olmayan odalara -1 konuldu.
Kullanıcıdan aldığımız giriş oda numarası çıkış oda numarası ve iterasyon sayısını kullanarak Q matrisi oluşturuldu. Q matrisindeki değerler iterasyon ile yenilendi. En son değerleri kullanarak giriş odacığından çıkış odacığına bir yol çizildi.
Çizim işlemi için allegro kütüphanesi kullanıldı.
