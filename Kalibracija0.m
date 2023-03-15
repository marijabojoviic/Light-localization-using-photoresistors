%pkg load arduino;
%pkg load instrument-control;
%a0(1:10)=0;
brojUnosa=10;
d0=[100];
for i=2:brojUnosa
    d0(i)=d0(i-1)+50*sqrt(2);
end
delete(instrfind({'Port'},{'COM3'}));
a=arduino('COM3', 'Uno');
n=1;
while(n<=brojUnosa)%broj unosa
if(readDigitalPin(a,"D3")==1)
        a0(n)=readVoltage(a,'A0');
        disp(n);
        n=n+1;
        pause(1);
end
end
