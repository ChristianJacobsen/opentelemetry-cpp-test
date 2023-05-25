#include "fmt/core.h"

#include "opentelemetry/exporters/ostream/span_exporter_factory.h"
#include "opentelemetry/sdk/trace/simple_processor_factory.h"
#include "opentelemetry/sdk/trace/tracer_provider_factory.h"
#include "opentelemetry/trace/provider.h"

#include <cstdlib>
#include <memory>
#include <utility>

void foo() {
    // Get a tracer from the global trace provider
    auto tracer = opentelemetry::trace::Provider::GetTracerProvider()->GetTracer("example_trace");

    // Start a span
    auto span = tracer->StartSpan("foo");

    // Set an attribute
    span->SetAttribute("key", 123);

    // Add an event
    span->AddEvent("event in foo");

    // End the span
    span->End();
}

void bar() {
    // Get a tracer from the global trace provider
    auto tracer = opentelemetry::trace::Provider::GetTracerProvider()->GetTracer("example_trace");

    // Start a span
    auto span = tracer->StartSpan("bar");

    // Set an attribute
    span->SetAttribute("key", 123);

    // Add an event
    span->AddEvent("event in bar");

    foo();

    // End the span
    span->End();
}

void baz() {
    // Get a tracer from the global trace provider
    auto tracer = opentelemetry::trace::Provider::GetTracerProvider()->GetTracer("example_trace");

    // Start a span
    auto span = tracer->StartSpan("baz");

    // Set an attribute
    span->SetAttribute("key", 123);

    // Add an event
    span->AddEvent("event in baz");

    bar();

    // End the span
    span->End();
}

int main() {
    // Create a trace provider with a simple processor and an ostream exporters
    // that will write to stdout.
    auto exporter = opentelemetry::exporter::trace::OStreamSpanExporterFactory::Create();
    auto processor = opentelemetry::sdk::trace::SimpleSpanProcessorFactory::Create(std::move(exporter));
    std::shared_ptr provider = opentelemetry::sdk::trace::TracerProviderFactory::Create(std::move(processor));

    // Set the global trace provider
    opentelemetry::trace::Provider::SetTracerProvider(provider);

    baz();

    // Reset the global trace provider
    opentelemetry::trace::Provider::SetTracerProvider(nullptr);

    return EXIT_SUCCESS;
}
