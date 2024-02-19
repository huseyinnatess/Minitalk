# Minitalk

Bu proje, Ecole 42'nin müfredatında bulunan bir iletişim projesidir. Minitalk, basit bir istemci-sunucu iletişim protokolü uygulamasını gerektirir. İstemci, sunucuya metin mesajları gönderirken, sunucu bu mesajları alır ve ekrana yazar.

## Özet
Bu proje, UNIX sinyallerini kullanarak haberleşmeyi öğretir. İstemci ve sunucu arasında sinyaller aracılığıyla mesajlar iletilecek ve sunucu bu mesajları alacak ve doğru bir şekilde ekrana yazdıracaktır.

## Kurulum
Repoyu klonlayın:
```
https://github.com/huseyinnatess/Minitalk.git
```

Proje dizinine gidin:
```
cd Minitalk
```

İstemci ve sunucu dosyalarını derleyin:
```
make
```

## Kullanım

Sunucuyu başlatın:
```
./server
```

Farklı bir terminalde aynı işlemleri uygulayarak istemciyi başlatın ve bir mesaj gönderin:
```
./client [server_pid] [mesaj]
```

`[server_pid]` parametresini sunucunun işlem kimliğiyle (./server komutunu çalıştırdığınızda görüntülenir) ve [mesaj] parametresini göndermek istediğiniz mesajla değiştirin.

