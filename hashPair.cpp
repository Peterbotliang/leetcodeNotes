template <typename T, typename U>
    struct myHash
    {
        void hash_combine(size_t &seed, const U &val) const
        {
            hash<U> Uhash;
            seed ^= Uhash(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        
        size_t operator() (const pair<T, U> &rhs) const
        {
            hash<T> Thash;
            size_t retval = Thash(rhs.first);
            hash_combine(retval, rhs.second);
            return retval;
        }
    };
