var
  num: int = 300
  num_ptr_1: ptr int = num.addr
  num_ptr_2: pointer = num.addr
  num_ref: ref int
  
  
echo repr(num_ptr_1)

echo repr(num_ptr_2)

echo repr(cast[ptr int](num_ptr_2))

proc ref_test(num: ref int) =
  echo repr(num)


num_ref = new int
num_ref[] = 100
ref_test(num_ref)