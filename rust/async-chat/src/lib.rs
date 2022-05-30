use serde::{Deserialize, Serialize};
use std::sync::Arc;

pub mod utils;

#[derive(Debug, Deserialize, Serialize, PartialEq)]
pub enum FromClient {
    Join { group_name: Arc<String> },
    Post {
        group_name: Arc<String>,
        message: Arc<String>,
    },
}

#[derive(Debug, Deserialize, Serialize, PartialEq)]
pub enum FromServer {
    Message {
        group_name: Arc<String>,
        message: Arc<String>,
    },
    Error(String),

}

#[test]
fn test_fromclient_json() {
    use std::sync::Arc;

    let from_client = FromClient::Post {
        group_name: Arc::new("Rust".to_string()),
        message: Arc::new("say hello".to_string()),
    };

    let json = serde_json::to_string(&from_client).unwrap();
    assert_eq!(json, r#"{"Post":{"group_name":"Rust","message":"say hello"}}"#);

    let packet = serde_json::from_str::<FromClient>(&json).unwrap();
    assert_eq!(packet, from_client);
}
