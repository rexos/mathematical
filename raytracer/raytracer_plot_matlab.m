ray_times = load('raytime.txt');
X = linspace(0,901,901);
plot(X,ray_times,'b.');
xlabel('Ray Number');
ylabel('Total travel time');
title('Grid raytracer travels')