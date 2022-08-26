function[]=diofantica(a,b,c)
% diofantica Da la solución general de ecuaciones diofanticas lineales en dos variables: ax+by=c en Z y Z[i]
[d,u,v]=bezout(a,b);		% Calcula mcd y coeficientes de Bezout
if resto(c,d)!=0		%Si mcd(a,c) no dovide a c, no tiene solución
	disp("La ecuación no tiene solución")
else			% En caso contrario, calcula una solución con ayuda de los coeficientes de Bezout
	x0=u*c/d;
	y0=v*c/d;
	h=ceil(-d*x0/b);	%Tomando el valor t= h, se obtiene una solución particular más cercana a (0,0)
	x0=x0+h*b/d;
	y0=y0-h*a/d;
end	
if imag(a)==0 && imag(b)==0 && imag(c) ==0	%Distinguimos los casos de coeficientes en Z y coeficientes en Z[i]
X=["x=" num2str(x0)  "+"  num2str(b/d) "t"];	% para poner paréntesis en el caso Z[i], 
Y=["x=" num2str(y0)  "-"  num2str(a/d) "t"];
XY=[X ; Y];
D=["La solucion general de la ecuación : " num2str(a) "x" "+" num2str(b) "y" "=" num2str(c) "  es:"];	
else
X=["x=(" num2str(x0)  ")+("  num2str(b/d) ")t"];
Y=["x=(" num2str(y0)  ")-("  num2str(a/d) ")t"];
XY=[X ; Y];
D=["La solucion general de la ecuación : (" num2str(a) ")x" "+(" num2str(b) ")y" "=" num2str(c) "  es:"];
end
disp(D)
disp(XY)
