pub use crate::ffi::*;

decl_opaque! {
    sfStdString;
    sfStdStringVector;
    sfString;
    sfInputStream;
    /// Utility type that measures the elapsed time.
    ///
    /// Its provides the most precise time that the underlying OS can
    /// achieve (generally microseconds or nanoseconds).
    /// It also ensures monotonicity, which means that the returned time can never go backward,
    /// even if the system time is changed.
    ///
    /// # Usage example
    /// ```
    /// # use sfml::system::Clock;
    /// let mut clock = Clock::start();
    /// // ...
    /// let time1 = clock.elapsed_time();
    /// // ...
    /// let time2 = clock.restart();
    /// ```
    ///
    /// The [`Time`](crate::system::Time) value returned by the clock can then be converted to
    /// a number of seconds, milliseconds or even microseconds.
    sfClock;
}

pub type sfTime = i64;

impl Dispose for sfStdString {
    unsafe fn dispose(&mut self) {
        sfStdString_destroy(self)
    }
}

impl<'a> IntoIterator for &'a sfStdStringVector {
    type IntoIter = sfStdStringVectorIter<'a>;
    type Item = &'a sfStdString;
    fn into_iter(self) -> Self::IntoIter {
        sfStdStringVectorIter {
            vec: self,
            len: unsafe { sfStdStringVector_getLength(self) },
            cursor: 0,
        }
    }
}

#[derive(Debug)]
pub struct sfStdStringVectorIter<'a> {
    vec: &'a sfStdStringVector,
    len: usize,
    cursor: usize,
}

impl<'a> Iterator for sfStdStringVectorIter<'a> {
    type Item = &'a sfStdString;
    fn next(&mut self) -> Option<&'a sfStdString> {
        if self.cursor >= self.len {
            return None;
        }
        unsafe {
            let item = sfStdStringVector_index(self.vec, self.cursor);
            self.cursor += 1;
            Some(&*item)
        }
    }
}

impl sfStdString {
    pub fn to_str(&self) -> Result<&str, Utf8Error> {
        std::str::from_utf8(self.data())
    }
}

impl PartialEq for sfStdString {
    fn eq(&self, other: &Self) -> bool {
        self.data() == other.data()
    }
}

impl PartialEq<sfStdString> for str {
    fn eq(&self, other: &sfStdString) -> bool {
        self.as_bytes() == other.data()
    }
}

impl Dispose for sfStdStringVector {
    unsafe fn dispose(&mut self) {
        sfStdStringVector_destroy(self);
    }
}

impl sfString {
    fn data(&self) -> &[u32] {
        unsafe {
            let len = sfString_getLength(self);
            let data = sfString_getData(self);
            std::slice::from_raw_parts(data, len)
        }
    }
}

impl Display for sfString {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let data = self.data();
        let ustr = widestring::U32Str::from_slice(data);
        write!(f, "{}", ustr.to_string_lossy())
    }
}

impl sfStdString {
    fn data(&self) -> &[u8] {
        unsafe {
            let len = sfStdString_getLength(self);
            let data = sfStdString_getData(self);
            std::slice::from_raw_parts(data as *const u8, len)
        }
    }
}

impl Display for sfStdString {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let data = self.data();
        let string = String::from_utf8_lossy(data);
        write!(f, "{}", string)
    }
}

type sfInputStreamReadFunc =
    Option<unsafe extern "C" fn(data: *mut c_void, size: i64, userData: *mut c_void) -> i64>;
type sfInputStreamSeekFunc = Option<unsafe extern "C" fn(pos: i64, user_data: *mut c_void) -> i64>;
type sfInputStreamTellFunc = Option<unsafe extern "C" fn(userData: *mut c_void) -> i64>;
type sfInputStreamGetSizeFunc = Option<unsafe extern "C" fn(user_data: *mut c_void) -> i64>;

include!("system_bindgen.rs");
