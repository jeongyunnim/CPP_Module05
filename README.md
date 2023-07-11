# CPP_Module05
Repetition and Exceptions

## Exercise 00: Mommy, when I grow up, I want to be a bureaucrat

> exception 클래스들은 Orthodox Canonical Form을 지킬 필요가 없다. 그러나 다른 클래스들은 지켜야 한다.

먼저, 거대한 관료주의를 이루는 가장 작은 톱니바퀴인 관료부터 시작해보자: Bureaucrat

Bureaucrat 클래스:
- const std::string name;
- int   grade
    : grade의 범위는 1(가장 높은 등급) ~ 150(가장 낮은 등급)이다.
- Bureaucrat의 grade를 유효하지 않은 값으로 인스턴스화를 시키려고 할 때, 예외를 던져야 한다.
> Bureaucrat::GradeTooHighException 또는 Bureaucrat::GradeTooLowException.
- getName()과 getGrade()를 제공해야 한다.
- grade를 증가하거나 감소시키는 멤버 메소드를 구현해야 한다.
- grade가 유효 범위를 벗어나면 생성자와 같이 예외를 던져야 한다.
> grade의 범위를 잘 생각하라. 1급이 가장 높은 등급이므로, 3급이 increase하면 2급이 된다.

- 예외를 던지는 것은 아래의 try catch문을 사용해야 한다.
```
try
{
    /* do some stuff with bureaucrats */
}
catch (std::exception & e)
{
    /* handle exception */
}
```

- 삽입 연산자 <<는 다음을 출력하도록 오버로딩 해야 한다.
<name>, bureaucrat grade <grade>.

## Exercise 01: Form up, maggots!