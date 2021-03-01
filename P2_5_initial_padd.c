/* d = a + b, 여기서 a, b, d는 다항식이다. */

d = Zero()

while(! IsZero(a) && ! IsZero(b)) do {
  switch COMPARE(LeadExp(a), LeadExp(b)) {
    case -1:
    d = Attach(d, Coef(b, LeadExp(b)), LeadExp(b));
    b = Remove(b, LeadExp(b));
    break;
    case 0: sum = Coef(a, LeadExp(a)) + Coef(b, LeadExp(b));
    if(sum) {
      Attach(d, sum, LeadExp(a));
      a = Remove(a, LeadExp(a));
      b = Remove(b, LeadExp(b));
    }
    break;
    case 1: d =
      Attach(d, Coef(a, LeadExp(a)), LeadExp(a));
      a = Remove(a, LeadExp(a));
  }
}

// insert any remaining terms of a or b into d
