# CPP_Module05
> Repetition and Exceptions

## Exercise 00: Mommy, when I grow up, I want to be a bureaucrat

> exception 클래스들은 Orthodox Canonical Form을 지킬 필요가 없다. 그러나 다른 클래스들은 지켜야 한다.

먼저, 거대한 관료주의를 이루는 가장 작은 톱니바퀴인 관료부터 시작해보자: Bureaucrat

Bureaucrat 클래스:
- const std::string name;
- int   grade
    : grade의 범위는 1(가장 높은 등급) ~ 150(가장 낮은 등급)이다.