clear; clc; clf;

a=load('data4_1000.txt');
b=load('data4_500.txt');
x=-100:100;
y=100000/(sqrt(2*pi)*1000)*exp(-x.^2/(2*1000));
figure(1)
histogram(a(:,2),400);
hold on
plot(x,y)
figure(2)
histogram(b(:,2),400);