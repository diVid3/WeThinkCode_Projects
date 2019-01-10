// This is simply to test whether javascript will continue executing the thread
// after an error has been thrown.

// Testing throwing a new error.

// Divides two numbers, b can't be 0.
function divTwoVal_a(a, b) {
  if (typeof(a) !== 'number' || typeof(b) !== 'number')
    throw new Error('Either a or b is not a number.')
  if (!b)
    throw new Error('b is 0, can\'t divide by 0');
  return (a / b);
}

console.log(divTwoVal_a(5, 2));
console.log('divTwoVal_a() executed.');

// Conclusion: throwing errors will kill the execution of the thread, this
// should be done in case of programmer errors. afiak. Notice that it's intended
// that a and b should be numbers and that b can't be 0. It should be documented
// that divTwoVal_a() is expecting those types and values

function divTwoVal_b(a, b) {
  try {
    if (!b) throw new Error('b is 0, can\'t divide by 0.')
    return (a / b);
  }
  catch (error) {
    console.log('error: ' + error);
  }
}

console.log(divTwoVal_b(5, 0));
console.log('divTwoVal_b() executed.');

// If you throw a new error in a try/catch block, it will be caught and thread
// execution will continue. This is better for operational errors only when 
// the operation will not lead to a programmer erro (breaking something down
// the line, as is the case when divTwoVal_b returns undefined to a caller
// function), afiak.
