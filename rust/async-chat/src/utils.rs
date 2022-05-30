use std::error::Error;

pub type ChatError = Box<dyn Error + Send + Sync + 'static>;
pub type ChatResult<T> = Result<T, ChatError>;

use async_std::prelude::*;
use serde::Serialize;
use std::marker::Unpin;

pub async fn send_as_json<S, P>(outbound: &mut S, packet: &P) -> ChatResult<()>
where
    S: async_std::io::Write + Unpin, // A Stream that implements async_std::io::Write.
    P: Serialize, { // A Packet that implements serde::Seralize
    // Serialize the packet to a temporary String with '\n'.
    let mut json = serde_json::to_string(&packet)?;
    json.push('\n');
    // Then write the String to the asynchronous stream.
    outbound.write_all(json.as_bytes()).await?;
    Ok(())
}

use serde::de::DeserializeOwned;

pub fn receive_as_json<S, P>(inbound: S) -> impl Stream<Item = ChatResult<P>>
    where S: async_std::io::BufRead + Unpin, // A stream that implements async_std::io::BufRead.
          P: DeserializeOwned, { // A Packet that implements serde::DeserializeOwned.
                                 // For efficiency, Deserialize can produce &str and &[u8] values 
                                 // that borrow their contents directly from the buffer it was from.
                                 // DeserializedOwned is always independent of the buffer it was 
                                 // deserialized from.
    inbound.lines()
        .map(|line| -> ChatResult<P> {
            let line = line?;
            let parsed = serde_json::from_str::<P>(&line)?;
            Ok(parsed)
        })
}
