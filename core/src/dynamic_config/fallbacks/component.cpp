#include <userver/dynamic_config/fallbacks/component.hpp>

#include <exception>
#include <stdexcept>
#include <string>

#include <userver/components/component.hpp>
#include <userver/dynamic_config/value.hpp>
#include <userver/fs/blocking/read.hpp>
#include <userver/yaml_config/merge_schemas.hpp>

USERVER_NAMESPACE_BEGIN

namespace components {

DynamicConfigFallbacks::DynamicConfigFallbacks(const ComponentConfig& config,
                                               const ComponentContext& context)
    : LoggableComponentBase(config, context), updater_(context) {
  try {
    auto fallback_config_contents = fs::blocking::ReadFileContents(
        config["fallback-path"].As<std::string>());

    dynamic_config::DocsMap fallback_config;
    fallback_config.Parse(fallback_config_contents, false);

    updater_.SetConfig(fallback_config);
  } catch (const std::exception& ex) {
    throw std::runtime_error(
        std::string("Cannot load fallback dynamic config: ") + ex.what());
  }
}
yaml_config::Schema DynamicConfigFallbacks::GetStaticConfigSchema() {
  return yaml_config::MergeSchemas<LoggableComponentBase>(R"(
type: object
description: Component that setup runtime configs based on fallbacks from file.
additionalProperties: false
properties:
    fallback-path:
        type: string
        description: a path to the fallback config to load the required config names from it
)");
}

}  // namespace components

USERVER_NAMESPACE_END
