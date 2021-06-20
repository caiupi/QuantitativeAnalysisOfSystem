function [] = analysis3general()
%N=5 PistoiaFirst
p1=[2.969323e+002,3.746053e+002,4.042885e+002,4.204587e+002,4.307785e+002,4.376618e+002,4.422201e+002,4.449875e+002];
p2=[2.942366e+002,3.756412e+002,4.141160e+002,4.394773e+002,4.600707e+002,4.780897e+002,4.940288e+002,5.069328e+002];
p3=[2.945534e+002,3.792083e+002,4.207423e+002,4.471539e+002,4.680012e+002,4.869843e+002,5.053661e+002,5.216913e+002];
p4=[2.946501e+002,3.804107e+002,4.237145e+002,4.514799e+002,4.728826e+002,4.924440e+002,5.120305e+002,5.297879e+002];
p5=[2.946690e+002,3.807240e+002,4.246267e+002,4.531092e+002,4.752031e+002,4.954561e+002,5.157486e+002,5.341105e+002];
p6=[2.946725e+002,3.808004e+002,4.248839e+002,4.536545e+002,4.761569e+002,4.968520e+002,5.175141e+002,5.361261e+002];
p7=[2.946731e+002,3.808187e+002,4.249583e+002,4.538401e+002,4.765093e+002,4.973970e+002,5.182247e+002,5.369356e+002];
p8=[2.946732e+002,3.808233e+002,4.249807e+002,4.538981e+002,4.766208e+002,4.975730e+002,5.184591e+002,5.372041e+002];
pistoiaFirst5=[p1;p2;p3;p4;p5;p6;p7;p8];
pistoiaFirst51=[p1(1:6);p2(1:6);p3(1:6);p4(1:6);p5(1:6);p6(1:6)];

%N=5 LuccaFirst
p1=[3.225535e+002,3.761124e+002,3.855438e+002,3.897496e+002,3.917671e+002,3.927147e+002,3.931447e+002,3.933257e+002];
p2=[3.282870e+002,4.193657e+002,4.482215e+002,4.643408e+002,4.743227e+002,4.801276e+002,4.832276e+002,4.846819e+002];
p3=[3.286938e+002,4.261397e+002,4.612694e+002,4.830844e+002,4.979485e+002,5.074033e+002,5.128143e+002,5.154627e+002];
p4=[3.287720e+002,4.274749e+002,4.641706e+002,4.878768e+002,5.050380e+002,5.165251e+002,5.233500e+002,5.267654e+002];
p5=[3.287905e+002,4.277379e+002,4.647658e+002,4.889467e+002,5.069873e+002,5.194844e+002,5.271018e+002,5.309749e+002];
p6=[3.287951e+002,4.277816e+002,4.648626e+002,4.891426e+002,5.074461e+002,5.203500e+002,5.283518e+002,5.324724e+002];
p7=[3.287962e+002,4.277872e+002,4.648727e+002,4.891727e+002,5.075466e+002,5.205788e+002,5.287282e+002,5.329591e+002];
p8=[3.287965e+002,4.277881e+002,4.648731e+002,4.891776e+002,5.075705e+002,5.206380e+002,5.288310e+002,5.330993e+002];
luccaFirst5=[p1;p2;p3;p4;p5;p6;p7;p8];
luccaFirst51=[p1(1:6);p2(1:6);p3(1:6);p4(1:6);p5(1:6);p6(1:6)];
%N=7 LuccaFirst
p1=[3.268000e+002,3.830324e+002,3.895158e+002,3.921201e+002,3.933516e+002,3.939363e+002];
p2=[3.295986e+002,4.283735e+002,4.558385e+002,4.697480e+002,4.786397e+002,4.842067e+002];
p3=[3.297237e+002,4.343192e+002,4.695703e+002,4.895054e+002,5.035092e+002,5.133135e+002];
p4=[3.297462e+002,4.352609e+002,4.725984e+002,4.945849e+002,5.110002e+002,5.231821e+002];
p5=[3.297513e+002,4.353738e+002,4.731849e+002,4.956663e+002,5.129632e+002,5.263218e+002];
p6=[3.297525e+002,4.353541e+002,4.732286e+002,4.957708e+002,5.132923e+002,5.271262e+002];
luccaFirst7=[p1;p2;p3;p4;p5;p6];
%N=7 pistoiaFirst
p1=[2.976093e+002,3.778727e+002,4.074936e+002,4.230251e+002,4.330660e+002,4.400201e+002];
p2=[2.941877e+002,3.747693e+002,4.109856e+002,4.323121e+002,4.479552e+002,4.613130e+002];
p3=[2.944085e+002,3.783172e+002,4.182602e+002,4.412745e+002,4.567328e+002,4.688965e+002];
p4=[2.944912e+002,3.796016e+002,4.218046e+002,4.468892e+002,4.631928e+002,4.750301e+002];
p5=[2.945083e+002,3.799548e+002,4.229712e+002,4.491052e+002,4.662267e+002,4.782680e+002];
p6=[2.945116e+002,3.800462e+002,4.233198e+002,4.498394e+002,4.673580e+002,4.796403e+002];
pistoiaFirst7=[p1;p2;p3;p4;p5;p6];


tiledlayout(2,2)
nexttile
surf(pistoiaFirst5);
xlabel( 'L' );
ylabel( 'P' );
zlabel( 'Treni che terminano la corsa' );
colorbar
title('10 treni nella linea ferroviaria con politica PistoiaFirst')

nexttile
surf(luccaFirst5);
xlabel( 'L' );
ylabel( 'P' );
zlabel( 'Treni che terminano la corsa' );
colorbar
title('10 treni nella linea ferroviaria con politica LuccaFirst')

nexttile
surf(pistoiaFirst7);
xlabel( 'L' );
ylabel( 'P' );
zlabel( 'Treni che terminano la corsa' );
colorbar
title('14 treni nella linea ferroviaria con politica PistoiaFirst')

nexttile
surf(luccaFirst7);
xlabel( 'L' );
ylabel( 'P' );
zlabel( 'Treni che terminano la corsa' );
colorbar
title('14 treni nella linea ferroviaria con politica LuccaFirst')



end

