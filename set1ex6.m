clear; clc; clf;
a=load("data6.txt");
b=load("data6distribution.txt");
figure(1)
h=histogram(a(:,2));
title('Κατανομή πλήθους χρόνων παγίδευσης -  c=10^{-4}')
xlabel("Χρόνος παγίδευσης (τ)")
ylabel("Πλήθος του κάθε χρόνου παγίδευσης")


x=b(:,1);
y(1)=b(1,2);
for i=2:length(b)
    y(i)=y(i-1)+b(i,2);
end
disp(y(49023))
for i=2:length(b)
    y(i)=100000-y(i);
end
for i=2:length(b)
    y(i)=y(i)/100000;
end

S=pi*x./log(x);
f=(1-0.0001).^S;

figure(2)
plot(x,y)
axis([0 length(x) 0 1])
title("Κατανομή πιθανότητας επιβίωσης των σωματιδίων -  c=10^{-4}")
xlabel("Χρόνος παγίδευσης (τ)")
ylabel("Πιθανότητα επιβίωσης σε κάθε χρονική στιγμή")
hold on
plot(x,f)
legend('Computational line','Theoritical line')