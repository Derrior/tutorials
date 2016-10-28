Some stuff about how shared_ptr and unique_ptr works
from <memory>
shared_ptr we can copy
unique_ptr we can't copy, but it is faster and more leightweight
all these pointers call delete for their dynamic allocated memory, when it is neccessary

