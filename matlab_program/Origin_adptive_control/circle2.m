function [y] = circle2(t)
a=50*sqrt(2);b=50*sqrt(2)-40;r=60;    
%x=[a-30*sqrt(2):0.01:a+30*sqrt(2)]';x�ķ�Χ��20����2��80����2
y=b+(r^2-(x-a).^2).^0.5;

end

