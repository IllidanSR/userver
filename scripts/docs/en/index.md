## userver C++ Framework 

**userver** is an open source asynchronous framework with a rich set of abstractions
for fast and comfortable creation of C++ microservices, services and utilities.

The framework solves the problem of efficient I/O interactions transparently for
the developers. As a result, with the framework you get straightforward source code,
avoid CPU-consuming context switches from OS, efficiently
utilize the CPU with a small amount of execution threads.


## Introduction
* @ref md_en_userver_intro
* @ref md_en_userver_tutorial_build


## Tutorial
* @ref md_en_userver_tutorial_hello_service
* @ref md_en_userver_tutorial_config_service
* @ref md_en_userver_tutorial_production_service
* @ref md_en_userver_tutorial_http_caching
* @ref md_en_userver_tutorial_flatbuf_service
* @ref md_en_userver_tutorial_grpc_service
* @ref md_en_userver_tutorial_postgres_service
* @ref md_en_userver_tutorial_mongo_service
* @ref md_en_userver_tutorial_redis_service


## Generic development
* @ref md_en_userver_component-system
    * @ref userver_clients "Clients"
    * @ref userver_http_handlers "HTTP Handlers"
    * @ref userver_components "Other components"
* @ref md_en_userver_synchronization
* @ref md_en_userver_formats
* @ref md_en_userver_logging


## Testing and benchmarking
* @ref md_en_userver_testing
* @ref md_en_userver_functional_testing


## Protocols
* @ref md_en_userver_grpc
* HTTP:
    * @ref clients::http::Client "Client"
    * @ref components::Server "Server"
* Low level:
    * @ref engine::io::TlsWrapper "TLS client and server socket"
    * @ref engine::io::Socket "TCP and UDP sockets"
    * @ref engine::subprocess::ProcessStarter "Subprocesses"


## Runtime service features
* @ref md_en_schemas_dynamic_configs
* @ref md_en_userver_log-level-running-service
* @ref md_en_userver_requests-in-flight
* @ref md_en_userver_service-monitor
* @ref md_en_userver_memory-profile-running-service
* @ref md_en_userver_dns-control


## Caches
* @ref md_en_userver_caches
* @ref md_en_userver_cache-dumps
* @ref pg_cache
* @ref md_en_userver_lru-cache

## PostgreSQL
* @ref pg_driver
* @ref pg_transactions
* @ref pg_run_queries
* @ref pg_process_results
* @ref pg_types
* @ref pg_user_row_types
* @ref pg_errors
* @ref pg_topology
* @ref pg_user_types
  * @ref pg_composite_types
  * @ref pg_enum
  * @ref pg_range_types
  * @ref pg_arrays
  * @ref pg_bytea

## ClickHouse
* @ref clickhouse_driver

## Non relational databases
* @ref md_en_userver_mongodb
* @ref md_en_userver_redis


## Opensource
* @ref md_en_userver_development_stability
* @ref md_en_userver_development_releases
* @ref CONTRIBUTING.md
* Distributed under [Apache-2.0 License](http://www.apache.org/licenses/LICENSE-2.0)
  * @ref THIRD_PARTY.md
