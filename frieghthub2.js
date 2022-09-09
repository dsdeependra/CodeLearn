let min = requests[0].startedAt;
let max = 0;

requests.forEach(request => {
  const completeAt = request.startedAt + request.ttl;
  if (request.startedAt < min) {
    min = request.startedAt;
  }
  if (completeAt > max) {
    max = completeAt;
  }
});

const cummulativeTtl = (max - min);

console.log(cummulativeTtl);