class Entry {
    public:
        Entry(int inputVal): val(inputVal), status(1) {};
        Entry() {
            status = 0;
        }

        int getStatus() {
            return status;
        }

        int getVal() {
            return val;
        }

        void setStatus(int a) {
            if (a > 2 || a < 0) return;
            status = a;
        }
    private:
        int val;
        int status = 0;
};