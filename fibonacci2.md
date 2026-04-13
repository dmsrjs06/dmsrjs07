<img width="2159" height="1179" alt="재귀적 방법" src="https://github.com/user-attachments/assets/79fd7be3-9bc6-4417-ad68-4d8eb4dd77fa" />
<img width="2830" height="1106" alt="순환적 방법" src="https://github.com/user-attachments/assets/c9916863-dce4-4c5b-bbb7-26154ad4acd5" />



구분 | 재귀적 방법 | 순환적 방법 |
|:---|:---:|---:|
시간 | 57초 | 5초
구현난이도 | 코드가 간단하고 직관적 | 약간 더 복잡하지만 크게 어렵진 않음
가독성 | 높음, 수학적 정의와 동일함 | 낮음, 변수 관리가 필수적임
성능 | 매우 느림 - ** 중복 계산이 다수 발생함 | 빠름
시간 복잡도 | O(2^n) | O(n)
장점 | 직관적 | 효율적
단점 | 함수 호출 호버헤드 가능성 증가, 오버플로우 위험 | 코드가 수학적으로 정의 가능함
